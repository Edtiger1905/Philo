/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:26:26 by epandele          #+#    #+#             */
/*   Updated: 2026/06/29 11:26:27 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	is_valid_int(const char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

static void	print_usage(void)
{
	printf("Error: Invalid arguments.\n");
	printf("Usage: ./philo number_of_philosophers");
	printf(" time_to_die time_to_eat time_to_sleep [number_of_meals]\n");
	printf("All arguments must be positive integers");
	printf(" greater than 0 and within the range of an int.\n");
}

int	parse_args(int ac, char **av, t_data *d)
{
	int	i;

	if (ac != 5 && ac != 6)
	{
		print_usage();
		return (1);
	}
	i = 1;
	while (i < ac)
	{
		if (!is_valid_int(av[i++]))
			return (1);
	}
	d->num_philos = ft_atol(av[1]);
	d->time_to_die = ft_atol(av[2]);
	d->time_to_eat = ft_atol(av[3]);
	d->time_to_sleep = ft_atol(av[4]);
	d->max_meals = (ac == 6) ? ft_atol(av[5]) : -1;
	if (d->num_philos < 1 || d->time_to_die < 1
		|| d->time_to_eat < 1 || d->time_to_sleep < 1
		|| (ac == 6 && d->max_meals < 1))
		return (1);
	return (0);
}
