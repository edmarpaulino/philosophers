/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:53 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/30 15:39:04 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("error: invalid input\n");
		return (2);
	}
	if (are_inputs_valid((const char **)&argv[1]))
		printf(GREEN "All inputs are valid\n" RESET);
	else
	{
		printf(RED "Error: Invalid arguments\n" RESET);
		return (1);
	}
	return (0);
}
