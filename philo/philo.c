#include "philo.h"

int main(int argc, char *argv[])
{
    t_philo *philos;
    t_fork  *forks;
    t_data  *data;
    int num_of_philos;

    if (argc != 5 && argc != 6)
        return (error_args());
    if (parse_input(argc, argv))
        return (-1);
    num_of_philos = ft_atoi(argv[1]);
    if (!(philos = create_philos(num_of_philos)))
        return (-1);
    if (!(forks = create_forks(num_of_philos)))
        return (free(philos), -1);
    if (!(data = init_threads(philos, forks, argv + 1)))
    {
        collecting_mutexes(forks, num_of_philos);
        return (free(philos), free(forks), -1);
    }
    detaching_threads(data, num_of_philos);
    check_death(data, num_of_philos);
    collecting_mutexes(forks, num_of_philos);
    return (free(data), free(philos), free(forks), 0);
}
