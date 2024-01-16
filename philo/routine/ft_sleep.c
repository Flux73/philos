#include "../philo.h"

void ft_sleep(t_data *list)
{
    pthread_mutex_lock(list->print_mutex);
    printf("%lu %d is sleeping\n", get_time_ms() - list->starting,
        list->philo->id_philo);
    pthread_mutex_unlock(list->print_mutex);
    sleeping(list->time_to_sleep);
}