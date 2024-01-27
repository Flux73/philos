/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:38:24 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 13:13:10 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_eat(t_data *data)
{
	sem_wait(data->sems->print_sem);
	printf("%lu %d is eating\n", get_time_ms() - data->starting, \
		data->philo_id);
	sem_post(data->sems->print_sem);
	data->last_meal_time = get_time_ms() - data->starting;
	(data->num_of_meals)--;
	sleeping(data->time_to_eat);
	sem_post(data->sems->forks_sem);
	sem_post(data->sems->forks_sem);
}
