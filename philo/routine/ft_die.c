/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:38:09 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 00:42:24 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_die(t_data *list, int i)
{
	pthread_mutex_lock(list[i].print_mutex);
	printf("%ld %d died\n", get_time_ms() - list[i].starting,
		list[i].philo->id_philo);
	pthread_mutex_destroy(list[i].print_mutex);
}
