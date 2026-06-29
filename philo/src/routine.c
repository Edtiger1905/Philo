/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:26:31 by epandele          #+#    #+#             */
/*   Updated: 2026/06/29 12:37:08 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(&p->right_fork->mutex);
		safe_print(p, "has taken a fork");
		pthread_mutex_lock(&p->left_fork->mutex);
	}
	else
	{
		pthread_mutex_lock(&p->left_fork->mutex);
		safe_print(p, "has taken a fork");
		pthread_mutex_lock(&p->right_fork->mutex);
	}
	safe_print(p, "has taken a fork");
}

static void	eat(t_philo *p)
{
	safe_print(p, "is eating");
	pthread_mutex_lock(&p->meal_mutex);
	p->last_meal_time = get_time_ms();
	p->meals_eaten++;
	pthread_mutex_unlock(&p->meal_mutex);
	precise_sleep(p->data->time_to_eat, p->data);
}

static void	run_cycle(t_philo *p)
{
	while (!check_dead_flag(p->data))
	{
		safe_print(p, "is thinking");
		take_forks(p);
		if (check_dead_flag(p->data))
		{
			pthread_mutex_unlock(&p->left_fork->mutex);
			pthread_mutex_unlock(&p->right_fork->mutex);
			return ;
		}
		eat(p);
		pthread_mutex_unlock(&p->left_fork->mutex);
		pthread_mutex_unlock(&p->right_fork->mutex);
		safe_print(p, "is sleeping");
		precise_sleep(p->data->time_to_sleep, p->data);
		precise_sleep(think_time(p->data), p->data);
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->data->num_philos == 1)
	{
		pthread_mutex_lock(&p->left_fork->mutex);
		safe_print(p, "has taken a fork");
		pthread_mutex_unlock(&p->left_fork->mutex);
		return (NULL);
	}
	if (p->id % 2 == 0)
		precise_sleep(p->data->time_to_eat, p->data);
	run_cycle(p);
	return (NULL);
}
