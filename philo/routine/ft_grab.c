#include "../philo.h"

void ft_grab(t_data *list, int i)
{
    pthread_mutex_lock(&(list->mutexes[i]->fork));
    pthread_mutex_lock(list->print_mutex);
    printf("%lu %d has taken a fork\n", get_time_ms() - list->starting,
        list->philo->id_philo);
    pthread_mutex_unlock(list->print_mutex);
}