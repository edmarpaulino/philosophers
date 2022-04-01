/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:53 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/01 09:36:49 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	t_philo	*philos;

	if (!are_args_valid((const int)argc, (const char **)argv))
		return (return_error(ARG_ERROR, NULL));
	if (init_data(argc, argv, &data))
		return (return_error(DATA_ERROR, NULL));
	if (init_philos(&philos, data))
		return (return_error(PHILOS_ERROR, NULL));
	start_philo(philos);
	destroy_philos(philos);
	return (0);
}
