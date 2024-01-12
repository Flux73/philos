#include "../philo.h"

t_fork *create_forks(int num_of_forks)
{
    t_fork *arr;
    int i;

    arr = (t_fork *)malloc((sizeof(t_fork) * num_of_forks));
    if (!arr)
        return (NULL);
    i = -1;
    while (++i < num_of_forks)
    {
        arr[i].id_fork = i + 1;
        arr[i].is_held = 0;
        if (pthread_mutex_init(&(arr[i].fork), NULL) != 0)
            return (collecting_mutexes(arr, i), free(arr), NULL);
    }
    return (arr);
}