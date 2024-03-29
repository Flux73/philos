/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detaching_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:35:23 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/26 22:36:45 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	detaching_threads(t_data *data, int num_of_philos)
{
	int	i;

	i = -1;
	while (++i < num_of_philos)
		if (pthread_detach(data[i].philo->philo))
			return ;
}
