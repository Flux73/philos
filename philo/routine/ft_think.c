/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:39:15 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/26 22:39:18 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_think(t_data *list)
{
	pthread_mutex_lock(list->print_mutex);
	printf("%lu %d is thinking\n", get_time_ms() - list->starting,
		list->philo->id_philo);
	pthread_mutex_unlock(list->print_mutex);
}
