#include "philo.h"

// Stampa sicura con timestamp
void safe_print(t_philo *p, const char *msg)
{
    pthread_mutex_lock(&p->data->print_mutex);
    if (!p->data->dead)
    {
        long long t = get_time_ms() - p->data->start_time;
        printf("%lld%d%s\n", t, p->id, msg);
    }
    pthread_mutex_unlock(&p->data->print_mutex);
}

void take_forks(t_philo *p)
{
    // Filosofi pari: prima destra, poi sinistra — rompe la simmetria
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

void put_forks(t_philo *p)
{
    pthread_mutex_unlock(&p->left_fork->mutex);
    pthread_mutex_unlock(&p->right_fork->mutex);
}

void *philo_routine(void *arg)
{
    t_philo *p = (t_philo *)arg;

    // I filosofi pari aspettano un tick prima di partire
    // per distribuire l'accesso alle forchette fin dall'inizio
    if (p->id % 2 == 0)
        usleep(1000);

    while (1)
    {
        // Controlla se la simulazione è terminata
        pthread_mutex_lock(&p->data->dead_mutex);
        if (p->data->dead)
        {
            pthread_mutex_unlock(&p->data->dead_mutex);
            break ;
        }
        pthread_mutex_unlock(&p->data->dead_mutex);

        safe_print(p, "is thinking");
        take_forks(p);
        safe_print(p, "is eating");

        // Aggiorna last_meal sotto mutex
        pthread_mutex_lock(&p->meal_mutex);
        p->last_meal_time = get_time_ms();
        p->meals_eaten++;
        pthread_mutex_unlock(&p->meal_mutex);

        precise_sleep(p->data->time_to_eat);
        put_forks(p);
        safe_print(p, "is sleeping");
        precise_sleep(p->data->time_to_sleep);
    }
    return (NULL);
}