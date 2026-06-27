# include "philo.h"

void safe_print(t_philo *p, const char *msg)
{
	pthread_mutex_lock(&p->data->print_mutex);
	if(!p->data->dead)
	{
		long long t = get_time_ms() - p->data->start_time;
		printf("%lld%d%s\n", t, p->id, msg);
	}
	pthread_mutex_unlock(&p->data->print_mutex);
}