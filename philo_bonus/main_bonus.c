/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:12:48 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/05 10:45:23 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	t_philo	*philos;
	int		ret;

	if (!are_args_valid((const int)argc, (const char **)argv))
		return (return_error(ARG_ERROR, NULL, NULL));
	if (argc == 6 && ft_atoi(argv[5]) == 0)
		return (0);
	data = get_data((const int)argc, (const char **)argv);
	if (!data)
		return (return_error(DATA_ERROR, NULL, NULL));
	philos = get_philos(data);
	if (!philos)
		return (return_error(PHILOS_ERROR, data, NULL));
	if (philos->data->num_of_philos == 1)
		ret = start_alone_philo(philos);
	else
		ret = start_philo_bonus(philos);
	if (ret)
		return (return_error(ALGO_ERROR, data, philos));
	destroy_philos(philos);
	return (0);
}
