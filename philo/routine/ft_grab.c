/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:38:40 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/26 22:38:46 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_grab(t_data *list, int i)
{
	pthread_mutex_lock(&(list->mutexes[i]->fork));
	pthread_mutex_lock(list->print_mutex);
	printf("%lu %d has taken a fork\n", get_time_ms() - list->starting,
		list->philo->id_philo);
	pthread_mutex_unlock(list->print_mutex);
}
