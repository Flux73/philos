#include "../philo.h"

void check_death(t_data *philos, int num_of_philos)
{
    int i;
    while (1)
    {
        i = -1;
        while (++i < num_of_philos)
        {
            if (philos[i].num_of_meals != 0 && 
                    get_time_ms() - philos[i].starting - 
                        philos[i].last_meal_time >= philos[i].time_to_die)
                return (ft_die(philos, i));
        }
        i = -1;
        while (++i < num_of_philos)
        {
            if (philos[i].num_of_meals != 0)
                break ;
            if (philos[i].num_of_meals == 0 && i == num_of_philos - 1)
                return ;
        }
    }
}