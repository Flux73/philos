/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 01:07:39 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 13:23:37 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_sems
{
	sem_t	*print_sem;
	sem_t	*forks_sem;
	sem_t	*death_sem;
}	t_sems;

typedef struct s_data
{
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	starting;
	unsigned long	last_meal_time;
	t_sems			*sems;
	int				num_of_meals;

	int				philo_id;
	pid_t			philo;
}	t_data;

typedef struct s_main
{
	t_data		*philos;
	pthread_t	death_thread;
	t_sems		*sems;
	int			num_of_philos;
	int			i;
}	t_main;

unsigned long	get_time_ms(void);
void			sleeping(unsigned long time_ms);

int				ft_atoi(char *str);

int				error_args(void);

int				parse_input(int argc, char **av);

sem_t			*init_fork(int num_of_philos);
sem_t			*init_print(void);
sem_t			*init_death(void);
t_data			*init_philos(char **av, t_sems *sems);

void			ft_think(t_data *data);
void			ft_grab(t_data *data);
void			ft_eat(t_data *data);
void			ft_sleep(t_data *data);
void			*ft_die(void *data);

#endif