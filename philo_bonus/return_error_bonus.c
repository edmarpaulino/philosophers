/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:03:02 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/04 10:04:52 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	return_error(int error, t_data *data)
{
	if (error == ARG_ERROR)
	{
		ft_putstr_fd(RED "Error: Invalid arguments" RESET_NL, 2);
		return (error);
	}
	else if (error == DATA_ERROR)
		ft_putstr_fd(RED "Error: Failed to create data structure" RESET_NL, 2);
	else if (error == PHILOS_ERROR)
		ft_putstr_fd(RED "Error: Failed to create philo array" RESET_NL, 2);
	else if (error == ALGO_ERROR)
		ft_putstr_fd(RED "Error: Failed to exec philo algorithm" RESET_NL, 2);
	destroy_data(data, 1);
	return (error);
}
