/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philos_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:50:41 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/04 19:40:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*get_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)malloc(data->num_of_philos * sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = 0;
	while (i < data->num_of_philos)
	{
		philos[i].num = i + 1;
		philos[i].num_of_meals = 0;
		philos[i].last_meal_timestamp = get_timestamp();
		philos[i].data = data;
		i++;
	}
	return (philos);
}
