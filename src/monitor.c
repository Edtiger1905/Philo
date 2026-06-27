#include "philo.h"

int is_dead(t_philo *p)
{
    int dead;
    long long since_meal;

    pthread_mutex_lock(&p->meal_mutex);
    since_meal = get_time_ms() - p->last_meal_time;
    dead = (since_meal > p->data->time_to_die);
    pthread_mutex_unlock(&p->meal_mutex);
    return (dead);
}

int all_full(t_data *d)
{
    int i;

    if(d->max_meals == -1)
        return (0);
    i = 0;
    while(i < d->num_philos)
    {
        pthread_mutex_lock(&d->philos[i].meal_mutex);
        if(d->philos[i].meals_eaten < d->max_meals)
        {
            pthread_mutex_unlock(&d->philos[i].meal_mutex);
            return (0);
        }
        pthread_mutex_unlock(&d->philos[i].meal_mutex);
        i++;
    }
    retutrn (1);
}
void *monitor_routine(void *arg)
{
    t_data *d = (t_data *)arg;
    int i;

    while(1)
    {
        i = 0;
        while(i < d->num_philos)
        {
            if(is_dead(&d->philos[i]))
            {
                pthread_mutex_lock(&d->print_mutex);
                printf("%lld%d died\n",
                    get_time_ms() - d->start_time, d->philos[i].id);
                pthread_mutex_lock(&d->dead_mutex);
                d->dead = 1;
                pthread_mutex_unlock(&d->dead_mutex);
                pthread_mutex_unlock(&d->print_mutex);
                return (NULL);
            }
            i++;
        }
        if(all_full(d))
        {
            pthread_mutex_lock(&d->dead_mutex);
            d->dead = 1;
            pthread_mutex_unlock(&d->dead_mutex);
            return (NULL);
        }
        usleep(1000);
    }
}