/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:54:14 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 00:41:20 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_data(t_philo *philos, t_data *data, t_fork *forks, t_eve *eve)
{
	if (data)
		free(data);
	if (philos)
		free(philos);
	if (forks)
		free(forks);
	if (eve)
	{
		free(eve->print_mutex);
		free(eve);
	}
}

static void	handle_die(t_main *main)
{
	detaching_threads(main->data, main->num_of_philos);
	check_death(main->data, main->num_of_philos);
	collecting_mutexes(main->forks, main->num_of_philos, main->eve);
	free_data(main->philos, main->data, main->forks, main->eve);
}

int	main(int argc, char *argv[])
{
	t_main	main;

	if (argc != 5 && argc != 6)
		return (error_args());
	if (parse_input(argc, argv))
		return (-1);
	main.num_of_philos = ft_atoi(argv[1]);
	main.philos = create_philos(main.num_of_philos);
	if (!(main.philos))
		return (-1);
	main.forks = create_forks(main.num_of_philos);
	if (!(main.forks))
		return (free(main.philos), -1);
	main.eve = create_eve(main.num_of_philos);
	if (!(main.eve))
		return (free(main.philos), free(main.forks), -1);
	main.data = init_threads(main.philos, main.forks, main.eve, argv + 1);
	if (!(main.data))
	{
		collecting_mutexes(main.forks, main.num_of_philos, main.eve);
		return (free_data(main.philos, 0, main.forks, main.eve), -1);
	}
	handle_die(&main);
	return (0);
}
