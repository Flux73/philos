/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 01:28:54 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 13:15:37 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static int	args_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

static void	check_optional_arg(t_data *arr, char **av)
{
	if (args_len(av) == 5)
		arr->num_of_meals = ft_atoi(av[4]);
	else
		arr->num_of_meals = -1;
}

static void	routine(t_data *data)
{
	pthread_t	t;

	if (pthread_create(&t, 0, ft_die, data) == -1)
		exit(-1);
	pthread_detach(t);
	while (1)
	{
		ft_think(data);
		ft_grab(data);
		ft_think(data);
		ft_grab(data);
		ft_eat(data);
		if (data->num_of_meals == 0)
		{
			sem_close(data->sems->forks_sem);
			sem_close(data->sems->print_sem);
			sem_close(data->sems->death_sem);
			exit(0);
		}
		ft_sleep(data);
	}
}

static void	insert_times(t_data *arr, char **av)
{
	arr->time_to_die = ft_atoi(av[1]);
	arr->time_to_eat = ft_atoi(av[2]);
	arr->time_to_sleep = ft_atoi(av[3]);
}

t_data	*init_philos(char **av, t_sems *sems)
{
	int				i;
	pid_t			pid;
	t_data			*arr;
	unsigned long	start;

	arr = (t_data *)malloc(sizeof(t_data) * ft_atoi(av[0]));
	if (!arr)
		exit(-1);
	i = -1;
	start = get_time_ms();
	while (++i < ft_atoi(av[0]))
	{
		pid = fork();
		arr[i].philo_id = i + 1;
		arr[i].philo = pid;
		arr[i].starting = start;
		arr[i].last_meal_time = get_time_ms() - arr[i].starting;
		check_optional_arg(&arr[i], av);
		insert_times(&arr[i], av);
		arr[i].sems = sems;
		if (pid == 0)
			routine(&arr[i]);
		usleep(50);
	}
	return (arr);
}
