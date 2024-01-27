/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_extra_mutexes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:37:55 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/26 23:52:40 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static pthread_mutex_t	*create_print(void)
{
	pthread_mutex_t	*arr;

	arr = malloc(sizeof(pthread_mutex_t));
	if (!arr)
		return (NULL);
	pthread_mutex_init(arr, NULL);
	return (arr);
}

t_eve	*create_eve(int num_of_philos)
{
	int				i;
	t_eve			*arr;
	pthread_mutex_t	*print_mtx;

	arr = (t_eve *)malloc((sizeof(t_eve) * num_of_philos));
	if (!arr)
		return (NULL);
	print_mtx = create_print();
	if (!print_mtx)
		return (NULL);
	i = -1;
	while (++i < num_of_philos)
	{
		arr[i].print_mutex = print_mtx;
		pthread_mutex_init(&(arr[i].last_meal_mutex), NULL);
		pthread_mutex_init(&(arr[i].num_of_meals_mutex), NULL);
	}
	return (arr);
}
