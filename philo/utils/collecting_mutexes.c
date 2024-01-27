/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collecting_mutexes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:35:16 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 18:06:56 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	collecting_mutexes(t_fork *forks, int num_of_forks, t_eve *eve)
{
	int	i;

	i = -1;
	while (++i < num_of_forks)
		if (pthread_mutex_destroy(&(forks[i].fork)))
			return ;
	i = -1;
	pthread_mutex_destroy(eve->print_mutex);
	while (eve && ++i < num_of_forks)
	{
		pthread_mutex_destroy(&(eve[i].last_meal_mutex));
		pthread_mutex_destroy(&(eve[i].num_of_meals_mutex));
	}
}
