/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:37:16 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/31 17:34:06 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_philo **philos, t_data *data)
{
	size_t	array_size;
	int		i;

	array_size = sizeof(t_philo) * data->num_of_philos;
	*philos = (t_philo *)ft_lalloc(&data->free_me, array_size);
	if (!philos)
		return (-1);
	i = 0;
	while (i < data->num_of_philos)
	{
		(*philos)[i].philo_number = i + 1;
		(*philos)[i].meal_counter = 0;
		(*philos)[i].last_meal = 0;
		(*philos)[i].right_fork = &data->forks[i];
		if (i == data->num_of_philos - 1)
			(*philos)[i].left_fork = &data->forks[0];
		else
			(*philos)[i].left_fork = &data->forks[i + 1];
		pthread_mutex_init(&(*philos)[i].lock_last_meal, NULL);
		pthread_mutex_init(&(*philos)[i].lock_meal_counter, NULL);
		(*philos)[i].data = data;
		i++;
	}
	return (0);
}
