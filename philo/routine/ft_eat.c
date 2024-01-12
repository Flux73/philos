#include "../philo.h"

void ft_eat(t_data *list)
{
    printf("%lu %d is eating\n", get_time_ms() - list->starting,
        list->philo->id_philo);
    list->last_meal_time = get_time_ms() - list->starting;
    usleep(list->time_to_eat * 1000);
    (list->num_of_meals)--;
    pthread_mutex_unlock(&(list->mutexes[0]->fork));
    pthread_mutex_unlock(&(list->mutexes[1]->fork));
}