#include "../philo.h"

t_philo *create_philos(int num_of_philos)
{
    t_philo *arr;
    int i;

    arr = (t_philo *)malloc((sizeof(t_philo) * num_of_philos));
    if (!arr)
        return (NULL);
    i = 0;
    while (i < num_of_philos)
    {
        arr[i].id_philo = i + 1; 
        i++;
    }
    return (arr);
}