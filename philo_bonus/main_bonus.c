/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:12:48 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/04 20:12:49 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	t_philo	*philos;

	if (!are_args_valid((const int)argc, (const char **)argv))
		return (1);
	data = get_data((const int)argc, (const char **)argv);
	if (!data)
		return (2);
	philos = get_philos(data);
	if (!philos)
	{
		destroy_data(data);
		return (3);
	}
	printf("Ok\n");
	destroy_philos(philos);
	return (0);
}
