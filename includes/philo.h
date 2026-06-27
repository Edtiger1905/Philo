#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* ----------LIBRARIES---------- */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_fork {
    pthread_mutex_t mutex;
    int             id;
} t_fork;

typedef struct s_philo
{
    int             id;
    t_fork          *left_fork;
    t_fork          *right_fork;
    long long       last_meal_time;
    int             meals_eaten;
    pthread_mutex_t meal_mutex;
    t_data          *data; 

}   t_philo;

typedef struct s_data
{
    int             num_philos;
    long long       time_to_die;
    long long       time_to_eat;
    long long       time_to_sleep;
    int             max_meals;
    long long       start_time;
    int             dead;
    pthread_mutex_t dead_mutex;
    pthread_mutex_t print_mutex;
    t_fork          *forks;
    t_philo         *philos

}   t_data;

#endif