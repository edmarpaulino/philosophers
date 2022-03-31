/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:17:08 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/31 17:33:16 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_philos(t_philo *philos)
{
	int	i;
	int	array_len;

	if (!philos)
		return ;
	i = 0;
	array_len = philos[0].data->num_of_philos;
	while (i < array_len)
	{
		pthread_mutex_destroy(&philos[i].lock_last_meal);
		pthread_mutex_destroy(&philos[i].lock_meal_counter);
		i++;
	}
	destroy_data(philos[0].data);
}
