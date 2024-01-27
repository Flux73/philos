/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:49:06 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 00:42:16 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*create_philos(int num_of_philos)
{
	t_philo	*arr;
	int		i;

	arr = (t_philo *)malloc((sizeof(t_philo) * num_of_philos));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < num_of_philos)
	{
		arr[i].id_philo = i + 1;
		i++;
	}
	return (arr);
}
