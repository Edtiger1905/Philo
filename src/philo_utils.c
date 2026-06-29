/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:44:10 by epandele          #+#    #+#             */
/*   Updated: 2026/06/29 12:37:47 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *p)
{
	int			dead;
	long long	since_meal;

	pthread_mutex_lock(&p->meal_mutex);
	since_meal = get_time_ms() - p->last_meal_time;
	dead = (since_meal >= p->data->time_to_die);
	pthread_mutex_unlock(&p->meal_mutex);
	return (dead);
}

void	safe_print(t_philo *p, const char *msg)
{
	pthread_mutex_lock(&p->data->print_mutex);
	if (!check_dead_flag(p->data))
		printf("%lld %d %s\n", get_time_ms() - p->data->start_time,
			p->id, msg);
	pthread_mutex_unlock(&p->data->print_mutex);
}

long long	think_time(t_data *d)
{
	long long	t;

	t = (d->time_to_die - d->time_to_eat - d->time_to_sleep) / 2;
	if (t < 0)
		t = 0;
	return (t);
}
