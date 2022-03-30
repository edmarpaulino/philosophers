/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:53 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/30 18:47:00 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	if (!are_args_valid((const int)argc, (const char **)argv))
	{
		printf(RED "Error: Invalid arguments\n" RESET);
		return (1);
	}
	printf(GREEN "All inputs are valid\n" RESET);
	return (0);
}
