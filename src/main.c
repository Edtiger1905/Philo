#include "philo.h"

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	*threads;
	pthread_t	monitor;
	int		i;

	if (parse_args(ac, av, &data))
		return (1);
	if (init_data(&data))
		return (1);
	threads = malloc(sizeof(pthread_t) * data.num_philos);
	if (!threads)
	{
		cleanup(&data, NULL, 0);
		return (1);
	}
	i = 0;
	while (i < data.num_philos)
	{
		pthread_create(&threads[i], NULL, philo_routine, &data.philos[i]);
		i++;
	}
	pthread_create(&monitor, NULL, monitor_routine, &data);
	cleanup(&data, threads, monitor);
	return (0);
}
