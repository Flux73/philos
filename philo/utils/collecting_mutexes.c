#include "../philo.h"

void collecting_mutexes(t_fork *forks, int num_of_forks, t_eve *eve)
{
    int i;

    i = -1;
    while (++i < num_of_forks)
        if (pthread_mutex_destroy(&(forks[i].fork)))
            return ;
    i = -1;
    while (eve && ++i < num_of_forks)
    {
        pthread_mutex_destroy(&(eve[i].last_meal_mutex));
        pthread_mutex_destroy(&(eve[i].num_of_meals_mutex));
    }
}