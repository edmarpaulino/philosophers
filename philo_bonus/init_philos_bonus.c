/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:00:29 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 19:08:07 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philos(t_philo **philos, t_data *data)
{
	size_t	arr_size;
	int		i;

	arr_size = sizeof(t_philo) * data->num_of_philos;
	*philos = (t_philo *)ft_lalloc(&data->free_me, arr_size);
	if (!*philos)
		return (-1);
	i = 0;
	while (i < data->num_of_philos)
	{
		(*philos)[i].number = i + 1;
		(*philos)[i].total_meals = 0;
		(*philos)[i].last_meal = get_timestamp();
		(*philos)[i].data = data;
		i++;
	}
	return (0);
}
