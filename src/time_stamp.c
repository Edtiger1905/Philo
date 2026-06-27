#include "philo.h"

// Restituisce il tempo corrente in millisecondi
long long get_time_ms(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (((long long)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

// Attesa precisa: controlla ogni 500 µs per evitare drift
void precise_sleep(long long ms)
{
    long long start = get_time_ms();

    while (get_time_ms() - start < ms)
        usleep(500);  // controlla ogni 0.5 ms
}
