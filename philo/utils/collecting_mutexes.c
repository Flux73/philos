#include "../philo.h"

void collecting_mutexes(t_fork *forks, int num_of_forks)
{
    int i;

    i = -1;
    while (++i < num_of_forks)
        if (pthread_mutex_destroy(&(forks[i].fork)))
            return ;
}