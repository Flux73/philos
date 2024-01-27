/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:44:13 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 13:15:14 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

sem_t	*init_fork(int num_of_philos)
{
	sem_t	*forks_sem;

	sem_unlink("sem");
	forks_sem = sem_open("sem", O_CREAT, 0644, num_of_philos);
	if (forks_sem == SEM_FAILED)
		exit(-1);
	return (forks_sem);
}
