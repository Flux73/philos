#include "../philo.h"

void detaching_threads(t_data *data, int num_of_philos)
{
    int i;

    i = -1;
    while (++i < num_of_philos)
        if (pthread_detach(data[i].philo->philo))
            return ;
}