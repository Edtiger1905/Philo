#include "philo.h"

static int	init_philos(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->num_philos)
	{
		d->philos[i].id = i + 1;
		d->philos[i].left_fork = &d->forks[i];
		d->philos[i].right_fork = &d->forks[(i + 1) % d->num_philos];
		d->philos[i].last_meal_time = d->start_time;
		d->philos[i].meals_eaten = 0;
		d->philos[i].data = d;
		if (pthread_mutex_init(&d->philos[i].meal_mutex, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	init_data(t_data *d)
{
	int	i;

	d->forks = malloc(sizeof(t_fork) * d->num_philos);
	d->philos = malloc(sizeof(t_philo) * d->num_philos);
	if (!d->forks || !d->philos)
	{
		free(d->forks);
		free(d->philos);
		return (1);
	}
	d->dead = 0;
	d->start_time = get_time_ms();
	pthread_mutex_init(&d->dead_mutex, NULL);
	pthread_mutex_init(&d->print_mutex, NULL);
	i = 0;
	while (i < d->num_philos)
	{
		d->forks[i].id = i;
		if (pthread_mutex_init(&d->forks[i].mutex, NULL) != 0)
			return (1);
		i++;
	}
	return (init_philos(d));
}

void	cleanup(t_data *d, pthread_t *threads, pthread_t monitor)
{
	int	i;

	i = 0;
	if (threads)
	{
		while (i < d->num_philos)
			pthread_join(threads[i++], NULL);
		pthread_join(monitor, NULL);
	}
	i = 0;
	while (i < d->num_philos)
	{
		pthread_mutex_destroy(&d->forks[i].mutex);
		pthread_mutex_destroy(&d->philos[i].meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&d->dead_mutex);
	pthread_mutex_destroy(&d->print_mutex);
	free(d->forks);
	free(d->philos);
	free(threads);
}
