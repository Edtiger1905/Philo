/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:44:10 by epandele          #+#    #+#             */
/*   Updated: 2026/06/29 11:44:14 by epandele         ###   ########.fr       */
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
