#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <signal.h>
#include <semaphore.h>
#include <fcntl.h>
#include <limits.h>

typedef struct s_data
{
    unsigned long time_to_die;
    unsigned long time_to_eat;
    unsigned long time_to_sleep;
    unsigned long starting;
    unsigned long last_meal_time;
    sem_t *print_sem;
    sem_t *forks_sem;
    int num_of_meals;

    int philo_id;
    pid_t philo;
}   t_data;

unsigned long get_time_ms(void);

int		ft_atoi(char *str);

int error_args(void);

int parse_input(int argc, char **av);

sem_t *init_fork(int num_of_philos);
sem_t *init_print(void);
t_data *init_philos(char **av, sem_t *forks_sem, sem_t *print_sem);


#endif