/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:44:21 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 13:14:10 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

sem_t	*init_print(void)
{
	sem_t	*print_sem;

	sem_unlink("sem_print");
	print_sem = sem_open("sem_print", O_CREAT, 0644, 1);
	if (print_sem == SEM_FAILED)
		exit(-1);
	return (print_sem);
}
