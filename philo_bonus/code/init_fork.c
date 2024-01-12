#include "../philo_bonus.h"

sem_t *init_fork(int num_of_philos)
{
    sem_t *forks_sem;

    sem_unlink("sem");
    forks_sem = sem_open("sem", O_CREAT, 0644, num_of_philos);
    return (forks_sem);
}   