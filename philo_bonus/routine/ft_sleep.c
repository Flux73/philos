/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:38:49 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 13:13:19 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_sleep(t_data *data)
{
	sem_wait(data->sems->print_sem);
	printf("%lu %d is sleeping\n", get_time_ms() - data->starting, \
		data->philo_id);
	sem_post(data->sems->print_sem);
	sleeping(data->time_to_sleep);
}
