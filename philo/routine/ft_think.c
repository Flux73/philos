#include "../philo.h"

void ft_think(t_data *list)
{
    printf("%lu %d is thinking\n", get_time_ms() - list->starting,
        list->philo->id_philo);
}