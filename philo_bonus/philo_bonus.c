#include "philo_bonus.h"

int main(int argc, char *argv[])
{
    sem_t *forks_sem;
    sem_t *print_sem;
    t_data *philos;
    int i;

    if (argc != 5 && argc != 6)
        return (error_args());
    if (parse_input(argc, argv))
        return (-1);
    forks_sem = init_fork(ft_atoi(argv[1]));
    print_sem = init_print();
    philos = init_philos(argv + 1, forks_sem, print_sem);
    while (++i < ft_atoi(argv[1]))
        waitpid(philos[0].philo, 0, 0);
    sem_close(forks_sem);
    sem_close(print_sem);
    sem_unlink("sem");
    sem_unlink("sem_print");
    free(philos);
    return (0);
}