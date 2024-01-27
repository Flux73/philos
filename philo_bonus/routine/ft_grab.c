/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:38:40 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 13:13:15 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_grab(t_data *data)
{
	sem_wait(data->sems->forks_sem);
	sem_wait(data->sems->print_sem);
	printf("%lu %d has taken a fork\n", get_time_ms() - data->starting, \
		data->philo_id);
	sem_post(data->sems->print_sem);
}
