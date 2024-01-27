/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:39:15 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 01:42:24 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_think(t_data *data)
{
	sem_wait(data->sems->print_sem);
	printf("%lu %d is thinking\n", get_time_ms() - data->starting, \
		data->philo_id);
	sem_post(data->sems->print_sem);
}
