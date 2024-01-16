#include "../philo.h"

void ft_eat(t_data *list)
{   
    pthread_mutex_lock(list->print_mutex);
    printf("%lu %d is eating\n", get_time_ms() - list->starting,
        list->philo->id_philo);
    pthread_mutex_unlock(list->print_mutex);
    pthread_mutex_lock(&(list->eve->last_meal_mutex));
    list->last_meal_time = get_time_ms() - list->starting;
    pthread_mutex_unlock(&(list->eve->last_meal_mutex));
    sleeping(list->time_to_eat);
    pthread_mutex_lock(&(list->eve->num_of_meals_mutex));
    (list->num_of_meals)--;
    pthread_mutex_unlock(&(list->eve->num_of_meals_mutex));
    pthread_mutex_unlock(&(list->mutexes[0]->fork));
    pthread_mutex_unlock(&(list->mutexes[1]->fork));
}