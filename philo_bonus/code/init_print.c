#include "../philo_bonus.h"

sem_t *init_print(void)
{
    sem_t *print_sem;

    sem_unlink("sem_print");
    print_sem = sem_open("sem_print", O_CREAT, 0644, 1);
    return (print_sem);
}