/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 01:00:30 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/27 01:00:41 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	parse_input(int argc, char **av)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_atoi(av[i]) < 1)
		{
			printf("Error: Invalid input!\n");
			printf("Input must be in range of 1 and\
				Max_INT for each argument :)\n");
			return (1);
		}
	}
	return (0);
}
