/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:12:48 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 11:36:57 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	t_philo	*philos;

	if (!are_args_valid((const int)argc, (const char **)argv))
		return (return_error(ARG_ERROR, NULL));
	if (init_data(argc, argv, &data))
		return (return_error(DATA_ERROR, data));
	if (init_philos(&philos, data))
		return (return_error(PHILOS_ERROR, data));
	if (start_philo(philos))
		return (return_error(ALGO_ERROR, data));
	destroy_data(data);
	return (0);
}
