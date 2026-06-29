/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:26:22 by epandele          #+#    #+#             */
/*   Updated: 2026/06/29 12:37:43 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead_flag(t_data *d)
{
	int	dead;

	pthread_mutex_lock(&d->dead_mutex);
	dead = d->dead;
	pthread_mutex_unlock(&d->dead_mutex);
	return (dead);
}

static int	all_full(t_data *d)
{
	int	i;

	if (d->max_meals == -1)
		return (0);
	i = 0;
	while (i < d->num_philos)
	{
		pthread_mutex_lock(&d->philos[i].meal_mutex);
		if (d->philos[i].meals_eaten < d->max_meals)
		{
			pthread_mutex_unlock(&d->philos[i].meal_mutex);
			return (0);
		}
		pthread_mutex_unlock(&d->philos[i].meal_mutex);
		i++;
	}
	return (1);
}

static void	set_dead_and_print(t_data *d, int i)
{
	pthread_mutex_lock(&d->dead_mutex);
	d->dead = 1;
	pthread_mutex_unlock(&d->dead_mutex);
	pthread_mutex_lock(&d->print_mutex);
	printf("%lld %d died\n",
		get_time_ms() - d->start_time, d->philos[i].id);
	pthread_mutex_unlock(&d->print_mutex);
}

static int	check_deaths(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->num_philos)
	{
		if (is_dead(&d->philos[i]))
		{
			set_dead_and_print(d, i);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*d;

	d = (t_data *)arg;
	while (1)
	{
		if (check_deaths(d))
			return (NULL);
		if (all_full(d))
		{
			pthread_mutex_lock(&d->dead_mutex);
			d->dead = 1;
			pthread_mutex_unlock(&d->dead_mutex);
			return (NULL);
		}
		usleep(1000);
	}
}
