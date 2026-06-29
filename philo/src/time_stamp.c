/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:26:43 by epandele          #+#    #+#             */
/*   Updated: 2026/06/29 12:37:51 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((long long)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	precise_sleep(long long ms, t_data *d)
{
	long long	start;

	start = get_time_ms();
	while (get_time_ms() - start < ms)
	{
		if (check_dead_flag(d))
			return ;
		usleep(500);
	}
}
