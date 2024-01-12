#include "../philo.h"

void ft_sleep(t_data *list)
{
    printf("%lu %d is sleeping\n", get_time_ms() - list->starting,
        list->philo->id_philo);
    usleep(list->time_to_sleep * 1000);
}