/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:03:02 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/31 19:19:25 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	return_error(int error, t_data *data)
{
	if (error == ARG_ERROR)
		ft_putendl(RED "Error: Invalid arguments" RESET, 2);
	else if (error == DATA_ERROR)
		ft_putendl(RED "Error: Failed to create data structure" RESET, 2);
	else if (error == PHILOS_ERROR)
		ft_putendl(RED "Error: Failed to create philosophers array" RESET, 2);
	if (error == DATA_ERROR || error == PHILOS_ERROR)
		destroy_data(data);
	return (error);
}
