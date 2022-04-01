/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:53 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/01 11:01:53 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	t_philo	*philos;

	if (!are_args_valid((const int)argc, (const char **)argv))
		return (return_error(ARG_ERROR, NULL, NULL));
	if (init_data(argc, argv, &data))
		return (return_error(DATA_ERROR, data, NULL));
	if (init_philos(&philos, data))
		return (return_error(PHILOS_ERROR, data, NULL));
	if (start_philo(philos))
		return (return_error(ALGO_ERROR, data, philos));
	destroy_philos(philos);
	return (0);
}
