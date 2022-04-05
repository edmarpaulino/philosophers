/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philos_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:16:15 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/05 10:47:16 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	destroy_philos(t_philo *philos)
{
	t_data	*data;

	if (!philos)
		return ;
	data = philos->data;
	free(philos);
	destroy_data(data);
}
