/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:07:47 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/02 11:55:52 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief checks if all philosophers ate the stipulated maximum 
 * 
 * @param philos philosophers array
 * @return int 1 if yes or 0 if are not
 */
static int	all_philos_ate(t_philo *philos);

/**
 * @brief checks if the philosophers is dead and print on the screen that it is
 * dead and assign the flag to stop dinner
 * 
 * @param philo pointer to philosopher
 * @return int 1 if yes and 0 if is not
 */
static int	is_dead(t_philo *philo);

void	*waiter_algorithm(void *ptr)
{
	t_philo	*philos;
	int		i;
	int		arr_len;

	philos = (t_philo *)ptr;
	arr_len = philos[0].data->num_of_philos;
	while (!all_philos_ate(philos))
	{
		i = 0;
		while (i < arr_len)
		{
			if (is_dead(&philos[i]))
				return (NULL);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

static int	all_philos_ate(t_philo *philos)
{
	int	i;
	int	arr_len;
	int	total_meals;

	i = 0;
	arr_len = philos[i].data->num_of_philos;
	while (i < arr_len)
	{
		pthread_mutex_lock(&philos[i].lock_total_meals);
		total_meals = philos[i].total_meals;
		pthread_mutex_unlock(&philos[i].lock_total_meals);
		if (total_meals != philos[i].data->times_must_eat)
			return (0);
		i++;
	}
	return (1);
}

static int	is_dead(t_philo *philo)
{
	long	since_last_meal;

	pthread_mutex_lock(&philo->lock_last_meal);
	since_last_meal = get_timestamp() - philo->last_meal;
	pthread_mutex_unlock(&philo->lock_last_meal);
	if (since_last_meal <= philo->data->time_to_die)
		return (0);
	print_philo_action(philo, PHILO_DIED);
	pthread_mutex_lock(&philo->data->lock_dinner);
	philo->data->dinner_is_over = 1;
	pthread_mutex_unlock(&philo->data->lock_dinner);
	return (1);
}
