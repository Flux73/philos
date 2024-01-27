/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 01:07:12 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 13:09:32 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	sleeping(unsigned long time_ms)
{
	unsigned long	t;

	t = get_time_ms();
	while (get_time_ms() - t - 0 < time_ms)
	{
	}
}
