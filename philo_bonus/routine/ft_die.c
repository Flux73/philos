/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 01:45:49 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 13:12:49 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*ft_die(void *data)
{
	t_data	*dt;

	dt = (t_data *)data;
	while (1)
	{
		if (dt->num_of_meals != 0 && \
			get_time_ms() - dt->starting - dt->last_meal_time >= \
				dt->time_to_die)
		{
			sem_wait(dt->sems->print_sem);
			printf("%lu %d died\n", get_time_ms() - dt->starting, \
				dt->philo_id);
			sem_post(dt->sems->death_sem);
			exit(0);
		}
	}
}
