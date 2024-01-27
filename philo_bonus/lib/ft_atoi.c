/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 00:59:59 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 13:13:43 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_atoi(char *str)
{
	long	results;
	int		sign;

	sign = 1;
	results = 0;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1 && results * 10 + (*str - '0') > INT_MAX)
			return (-1);
		if (sign == -1 && results * 10 + (*str - '0') < INT_MIN)
			return (0);
		results = results * 10 + (*str - '0');
		str++;
	}
	return ((int)(results * sign));
}
