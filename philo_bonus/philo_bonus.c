/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 01:08:34 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 13:19:05 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	clean_sems(t_main *main)
{
	sem_unlink("sem");
	sem_unlink("sem_print");
	sem_unlink("sem_death");
	free(main->philos);
	free(main->sems);
}

static void	*check_death(void *main)
{
	t_main	*dt;
	int		i;

	dt = (t_main *)main;
	sem_wait(dt->sems->death_sem);
	i = -1;
	while (++i < dt->num_of_philos)
		kill(dt->philos[i].philo, SIGKILL);
	clean_sems(dt);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_main	main;

	if (argc != 5 && argc != 6)
		return (error_args());
	if (parse_input(argc, argv))
		return (-1);
	main.sems = malloc(sizeof(t_sems));
	if (!(main.sems))
		return (-1);
	main.sems->forks_sem = init_fork(ft_atoi(argv[1]));
	main.sems->print_sem = init_print();
	main.sems->death_sem = init_death();
	main.philos = init_philos(argv + 1, main.sems);
	main.num_of_philos = ft_atoi(argv[1]);
	if (pthread_create(&(main.death_thread), 0, check_death, &main))
		return (-1);
	pthread_detach(main.death_thread);
	main.i = -1;
	while (++(main.i) < main.num_of_philos)
		waitpid(main.philos[main.i].philo, 0, 0);
	clean_sems(&main);
	return (0);
}
