#include "../philo.h"

static int args_len(char **av)
{
    int i;

    i = 0;
    while (av[i])
        i++;
    return (i);
}

static void check_optional_arg(t_data *arr, char **av)
{
    if (args_len(av) == 5)
        arr->num_of_meals = ft_atoi(av[4]);
    else
        arr->num_of_meals = -1;
}

static void *routine(void *arg)
{
    t_data *list;

    list = (t_data *)arg;
    while (1)
    { 
        ft_think(list);
        ft_grab(list, 0);
        ft_think(list);
        ft_grab(list, 1);
        ft_eat(list);
        if (list->num_of_meals == 0)
            break ;
        ft_sleep(list);
    }
    return (NULL);
}

t_data *init_threads(t_philo *philos, t_fork *forks, char **av)
{
    t_data *arr;
    int i;
    long starting_time;

    arr = (t_data *)malloc(sizeof(t_data) * ft_atoi(av[0]));
    if (!arr)
        return (NULL);
    i = -1;
    starting_time = get_time_ms();
    while (++i < ft_atoi(av[0]))
    {
        arr[i].philo = &(philos[i]);
        arr[i].mutexes[0] = &(forks[(i + ft_atoi(av[0]) - 1) % ft_atoi(av[0])]);
        arr[i].mutexes[1] = &(forks[i]);
        arr[i].starting = starting_time;
        arr[i].last_meal_time = get_time_ms() - starting_time;
        check_optional_arg(&arr[i], av);
        arr[i].time_to_die = ft_atoi(av[1]);
        arr[i].time_to_eat = ft_atoi(av[2]);
        arr[i].time_to_sleep = ft_atoi(av[3]);
        if (pthread_create(&(philos[i].philo), NULL, &routine, &arr[i]) != 0)
            return (detaching_threads(arr, i), free(arr), NULL);
        usleep(50);
    }
    return (arr);
}