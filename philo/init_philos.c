/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:37:16 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/01 20:37:14 by edpaulin         ###   ########.fr       */
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
		(*philos)[i].number = i + 1;
		(*philos)[i].total_meals = 0;
		(*philos)[i].last_meal = get_timestamp();
		(*philos)[i].right_fork = &data->forks[i];
		(*philos)[i].left_fork = &data->forks[(i + 1) % data->num_of_philos];
		pthread_mutex_init(&(*philos)[i].lock_last_meal, NULL);
		pthread_mutex_init(&(*philos)[i].lock_total_meals, NULL);
		(*philos)[i].data = data;
		i++;
	}
	return (0);
}
