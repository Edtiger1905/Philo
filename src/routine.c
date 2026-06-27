#include "philo.h"

void	safe_print(t_philo *p, const char *msg)
{
	pthread_mutex_lock(&p->data->print_mutex);
	if (!p->data->dead)
		printf("%lld %d %s\n", get_time_ms() - p->data->start_time,
			p->id, msg);
	pthread_mutex_unlock(&p->data->print_mutex);
}

static void	take_forks(t_philo *p)
{
	if (p->data->num_philos == 1)
	{
		pthread_mutex_lock(&p->left_fork->mutex);
		safe_print(p, "has taken a fork");
		precise_sleep(p->data->time_to_die);
		pthread_mutex_unlock(&p->left_fork->mutex);
		return ;
	}
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

static void	put_forks(t_philo *p)
{
	pthread_mutex_unlock(&p->left_fork->mutex);
	pthread_mutex_unlock(&p->right_fork->mutex);
}

static void	eat(t_philo *p)
{
	safe_print(p, "is eating");
	pthread_mutex_lock(&p->meal_mutex);
	p->last_meal_time = get_time_ms();
	p->meals_eaten++;
	pthread_mutex_unlock(&p->meal_mutex);
	precise_sleep(p->data->time_to_eat);
}

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2 == 0)
		usleep(1000);
	while (!check_dead_flag(p->data))
	{
		safe_print(p, "is thinking");
		take_forks(p);
		if (p->data->num_philos == 1)
			return (NULL);
		eat(p);
		put_forks(p);
		safe_print(p, "is sleeping");
		precise_sleep(p->data->time_to_sleep);
	}
	return (NULL);
}
