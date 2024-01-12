#include "../philo.h"

void ft_die(t_data *list, int i)
{
    printf("%ld %d died\n", get_time_ms() - list[i].starting,
        list[i].philo->id_philo); 
}