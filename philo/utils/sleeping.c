/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:36:27 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/26 22:37:53 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	sleeping(unsigned long time_ms)
{
	unsigned long	t;

	t = get_time_ms();
	while (get_time_ms() - t - 0 < time_ms)
	{
	}
}
