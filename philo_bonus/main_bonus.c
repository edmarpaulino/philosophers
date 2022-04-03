/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:12:48 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 10:45:44 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (!are_args_valid((const int)argc, (const char **)argv))
	{
		printf(RED "Error: invalid arguments" RESET);
		return (1);
	}
	printf(GREEN "All arguments are valid\n" RESET);
	init_data(argc, argv, &data);
	destroy_data(data);
	return (0);
}
