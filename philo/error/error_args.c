/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoumni <smoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:48:19 by smoumni           #+#    #+#             */
/*   Updated: 2024/01/26 22:48:30 by smoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	error_args(void)
{
	printf("Error: Invalid number of arguments!\n");
	printf("Please provide 4 or 5 arguments:\n");
	printf("    1. Number of philosophers.\n");
	printf("    2. Time to die in milliseconds.\n");
	printf("    3. Time to eat in milliseconds.\n");
	printf("    4. Time to sleep in milliseconds.\n");
	printf("    5. Number of times each philosopher must eat (optional).\n");
	return (-1);
}
