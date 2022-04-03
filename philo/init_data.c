/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:50:59 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 15:47:40 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief init data mutexes
 * 
 * @param data structure that contains shared values
 * @return int 0 on success or -1 on failure
 */
static int	init_data_mutexes(t_data *data);

int	init_data(int argc, char **argv, t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
		return (-1);
	(*data)->num_of_philos = ft_atoi(argv[NUM_OF_PHILOS]);
	(*data)->time_to_die = ft_atoi(argv[TIME_TO_DIE]);
	(*data)->time_to_eat = ft_atoi(argv[TIME_TO_EAT]) * 1000;
	(*data)->time_to_sleep = ft_atoi(argv[TIME_TO_SLEEP]) * 1000;
	(*data)->times_must_eat = -1;
	if (argc == 6)
		(*data)->times_must_eat = ft_atoi(argv[TIMES_MUST_EAT]);
	(*data)->is_alone = ((*data)->num_of_philos == 1);
	(*data)->dinner_is_over = 0;
	(*data)->first_timestamp = get_timestamp();
	(*data)->free_me = NULL;
	return (init_data_mutexes(*data));
}

static int	init_data_mutexes(t_data *data)
{
	int		i;
	size_t	array_size;

	pthread_mutex_init(&data->lock_print, NULL);
	pthread_mutex_init(&data->lock_dinner, NULL);
	array_size = sizeof(t_mutex) * data->num_of_philos;
	data->forks = (t_mutex *)ft_lalloc(&data->free_me, array_size);
	if (!data->forks)
		return (-1);
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}
