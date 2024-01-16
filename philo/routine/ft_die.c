#include "../philo.h"

void ft_die(t_data *list, int i)
{
    pthread_mutex_lock(list[i].print_mutex);
    printf("%ld %d died\n", get_time_ms() - list[i].starting,
        list[i].philo->id_philo);
    pthread_mutex_destroy(list[i].print_mutex);
}