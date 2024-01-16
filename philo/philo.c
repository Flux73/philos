#include "philo.h"

void l()
{
    system("leaks philo");
}

static t_eve *create_eve(int num_of_philos)
{
    t_eve *arr;
    int i;

    arr = (t_eve *)malloc((sizeof(t_eve) * num_of_philos));
    if (!arr)
        return (NULL);
    i = -1;
    while (++i < num_of_philos)
    {
        pthread_mutex_init(&(arr[i].last_meal_mutex), NULL);
        pthread_mutex_init(&(arr[i].num_of_meals_mutex), NULL);
    } 
    return (arr);
}

static pthread_mutex_t *create_print(void)
{
    pthread_mutex_t *arr;

    arr = malloc(sizeof(pthread_mutex_t));
    if (!arr)
        return (NULL);
    pthread_mutex_init(arr, NULL);
    return (arr);
}

int main(int argc, char *argv[])
{
    t_main main;

    atexit(l);
    if (argc != 5 && argc != 6)
        return (error_args());
    if (parse_input(argc, argv))
        return (-1);
    main.num_of_philos = ft_atoi(argv[1]);
    if (!(main.philos = create_philos(main.num_of_philos)))
        return (-1);
    if (!(main.forks = create_forks(main.num_of_philos)))
        return (free(main.philos), -1);
    main.eve = create_eve(main.num_of_philos);
    main.print_mutex = create_print();
    if (!(main.data = init_threads(main.philos, main.forks, main.eve, main.print_mutex, argv + 1)))
    {
        collecting_mutexes(main.forks, main.num_of_philos, main.eve);
        return (free(main.philos), free(main.forks), -1);
    }
    detaching_threads(main.data, main.num_of_philos);
    check_death(main.data, main.num_of_philos);
    collecting_mutexes(main.forks, main.num_of_philos, main.eve);
    return (free(main.data), free(main.philos), free(main.eve), free(main.forks), free(main.print_mutex), 0);
}
