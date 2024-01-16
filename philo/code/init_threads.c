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

static void add_routine_time(char **av, t_data *arr, unsigned long start)
{
    check_optional_arg(arr, av);
    arr->starting = start;
    arr->last_meal_time = get_time_ms() - start;
    arr->time_to_die = ft_atoi(av[1]);
    arr->time_to_eat = ft_atoi(av[2]);
    arr->time_to_sleep = ft_atoi(av[3]);
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
        pthread_mutex_lock(&(list->eve->num_of_meals_mutex));
        if (list->num_of_meals == 0)
        {
            pthread_mutex_unlock(&(list->eve->num_of_meals_mutex));
            break ;
        }
        pthread_mutex_unlock(&(list->eve->num_of_meals_mutex));
        ft_sleep(list);
    }
    return (NULL);
}

t_data *init_threads(t_philo *philos, t_fork *forks, t_eve *eve, pthread_mutex_t *print_mutex, char **av)
{
    t_data *arr;
    int i;
    unsigned long starting_time;

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
        arr[i].eve = &eve[i];
        arr[i].print_mutex = print_mutex;
        add_routine_time(av, &arr[i], starting_time);
        if (pthread_create(&(philos[i].philo), NULL, &routine, &arr[i]) != 0)
            return (detaching_threads(arr, i), free(arr), NULL);
        usleep(50);
    }
    return (arr);
}
