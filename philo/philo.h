#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_eve
{
	pthread_mutex_t last_meal_mutex;
	pthread_mutex_t num_of_meals_mutex;
}	t_eve;

typedef struct s_philo
{
	int			id_philo;
	pthread_t	philo;
} t_philo;

typedef struct s_fork
{
    int id_fork;
    pthread_mutex_t fork;
} t_fork;

typedef struct s_data
{
	unsigned long	last_meal_time;
	unsigned long	starting;
	int		num_of_meals;

	unsigned long	time_to_die;
	unsigned long	time_to_sleep;
	unsigned long	time_to_eat;

	t_philo	*philo;
	t_fork	*mutexes[2];
	t_eve *eve;
	pthread_mutex_t *print_mutex;
} t_data;

typedef struct s_main
{
	t_philo *philos;
    t_fork  *forks;
    t_data  *data;
    int num_of_philos;
    t_eve *eve;
	pthread_mutex_t *print_mutex;
}	t_main;

int		ft_atoi(char *str);

void ft_think(t_data *list);
void ft_grab(t_data *list, int i);
void ft_eat(t_data *list);
void ft_sleep(t_data *list);
void ft_die(t_data *list, int i);

unsigned long	get_time_ms(void);
void collecting_mutexes(t_fork *forks, int num_of_forks, t_eve *phs);
void detaching_threads(t_data *philos, int num_of_philos);

int		error_args(void);

int		parse_input(int argc, char **av);

t_philo *create_philos(int num_of_philos);
t_fork	*create_forks(int num_of_forks);
void    check_death(t_data *philos, int num_of_philos);
t_data *init_threads(t_philo *philos, t_fork *forks, t_eve *eve, pthread_mutex_t *print_mutex, char **av);

void sleeping(unsigned long time_ms);

#endif


