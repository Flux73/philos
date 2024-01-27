/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_death.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 01:15:33 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 13:15:26 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

sem_t	*init_death(void)
{
	sem_t	*death_sem;

	sem_unlink("sem_death");
	death_sem = sem_open("sem_death", O_CREAT, 0644, 0);
	if (death_sem == SEM_FAILED)
		exit(-1);
	return (death_sem);
}
