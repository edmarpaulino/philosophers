/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:25:11 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 15:48:03 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief create all philo threads
 * 
 * @param philos array of philosophers
 * @return int 0 on success or -1 on failure
 */
static int	create_philo_threads(t_philo *philos);

/**
 * @brief join all philo threads
 * 
 * @param philos array of philosophers
 * @return int 0 on success or -1 on failure
 */
static int	join_philo_threads(t_philo *philos);

int	start_philo(t_philo *philos)
{
	pthread_t	waiter;

	if (philos[0].data->times_must_eat == 0)
		return (0);
	if (philos[0].data->first_timestamp == -1)
		return (-1);
	if (create_philo_threads(philos))
		return (-1);
	if (pthread_create(&waiter, NULL, &waiter_algorithm, philos))
		return (-1);
	if (join_philo_threads(philos))
		return (-1);
	if (pthread_join(waiter, NULL))
		return (-1);
	return (0);
}

static int	create_philo_threads(t_philo *philos)
{
	int	i;
	int	arr_len;

	i = 0;
	arr_len = philos[i].data->num_of_philos;
	while (i < arr_len)
	{
		if (pthread_create(&philos[i].thread, NULL, \
							&philo_algorithm, &philos[i]))
			return (-1);
		i++;
	}
	return (0);
}

static int	join_philo_threads(t_philo *philos)
{
	int	i;
	int	arr_len;

	i = 0;
	arr_len = philos[i].data->num_of_philos;
	while (i < arr_len)
	{
		if (pthread_join(philos[i].thread, NULL))
			return (-1);
		i++;
	}
	return (0);
}
