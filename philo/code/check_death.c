/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:38:54 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 00:03:05 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	check_death_timing(t_data *philos, int num_of_philos)
{
	int	i;

	i = -1;
	while (++i < num_of_philos)
	{
		pthread_mutex_lock(&(philos[i].eve->last_meal_mutex));
		pthread_mutex_lock(&(philos[i].eve->num_of_meals_mutex));
		if (philos[i].num_of_meals != 0 && \
			get_time_ms() - philos[i].starting - \
				philos[i].last_meal_time >= philos[i].time_to_die)
			return (ft_die(philos, i), 1);
		pthread_mutex_unlock(&(philos[i].eve->num_of_meals_mutex));
		pthread_mutex_unlock(&(philos[i].eve->last_meal_mutex));
	}
	return (0);
}

static int	check_meals_num(t_data *philos, int num_of_philos)
{
	int	i;

	i = -1;
	while (++i < num_of_philos)
	{
		pthread_mutex_lock(&(philos[i].eve->num_of_meals_mutex));
		if (philos[i].num_of_meals != 0)
		{
			pthread_mutex_unlock(&(philos[i].eve->num_of_meals_mutex));
			break ;
		}
		pthread_mutex_unlock(&(philos[i].eve->num_of_meals_mutex));
		pthread_mutex_lock(&(philos[i].eve->num_of_meals_mutex));
		if (i == num_of_philos - 1 && philos[i].num_of_meals == 0)
			return (1);
		pthread_mutex_unlock(&(philos[i].eve->num_of_meals_mutex));
	}
	return (0);
}

void	check_death(t_data *philos, int num_of_philos)
{
	while (1)
	{
		if (check_death_timing(philos, num_of_philos))
			return ;
		if (check_meals_num(philos, num_of_philos))
			return ;
	}
}
