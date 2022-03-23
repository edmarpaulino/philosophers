/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:53 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/23 15:01:11 by edpaulin         ###   ########.fr       */
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
	if (argc == 5)
	{
		printf("number of philosophers: %s\n", argv[1]);
		printf("time to die: %s\n", argv[2]);
		printf("time to eat: %s\n", argv[3]);
		printf("time to sleep: %s\n", argv[4]);
	}
	if (argc == 6)
	{
		printf("number of philosophers: %s\n", argv[1]);
		printf("time to die: %s\n", argv[2]);
		printf("time to eat: %s\n", argv[3]);
		printf("time to sleep: %s\n", argv[4]);
		printf("number of times each philosopher must eat: %s\n", argv[5]);
	}
	return (0);
}
