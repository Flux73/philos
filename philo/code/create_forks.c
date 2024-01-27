/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:48:43 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/26 23:52:51 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_fork	*create_forks(int num_of_forks)
{
	t_fork	*arr;
	int		i;

	arr = (t_fork *)malloc((sizeof(t_fork) * num_of_forks));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < num_of_forks)
	{
		arr[i].id_fork = i + 1;
		if (pthread_mutex_init(&(arr[i].fork), NULL) != 0)
			return (collecting_mutexes(arr, i, 0), free(arr), NULL);
	}
	return (arr);
}
