#include "../philo.h"

void check_death(t_data *philos, int num_of_philos)
{
    int i;
    while (1)
    {
        i = -1;
        while (++i < num_of_philos)
        {
            pthread_mutex_lock(&(philos[i].eve->last_meal_mutex));
            pthread_mutex_lock(&(philos[i].eve->num_of_meals_mutex));
            if (philos[i].num_of_meals != 0 && 
                    get_time_ms() - philos[i].starting - 
                        philos[i].last_meal_time >= philos[i].time_to_die)
                return (ft_die(philos, i));
            pthread_mutex_unlock(&(philos[i].eve->num_of_meals_mutex));
            pthread_mutex_unlock(&(philos[i].eve->last_meal_mutex));
        }
        i = -1;
        while (++i < num_of_philos)
        {
            pthread_mutex_lock(&(philos[i].eve->num_of_meals_mutex));
            if (philos[i].num_of_meals != 0)
            {
                pthread_mutex_unlock(&(philos[i].eve->num_of_meals_mutex));
                break ;
            }
            pthread_mutex_unlock(&(philos[i].eve->num_of_meals_mutex));
            pthread_mutex_lock(&(philos[i].eve->num_of_meals_mutex));
            if (i == num_of_philos - 1 && philos[i].num_of_meals == 0)
            {
                return ;
            }
            pthread_mutex_unlock(&(philos[i].eve->num_of_meals_mutex));
        }
    }
}