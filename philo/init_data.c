/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:50:59 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/31 15:30:03 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief allocate memory for mutexes and init them
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
	(*data)->time_to_eat = ft_atoi(argv[TIME_TO_EAT]);
	(*data)->time_to_sleep = ft_atoi(argv[TIME_TO_SLEEP]);
	(*data)->times_must_eat = -1;
	if (argc == 6)
		(*data)->times_must_eat = ft_atoi(argv[TIMES_MUST_EAT]);
	(*data)->is_alone = ((*data)->num_of_philos == 1);
	(*data)->first_stamp = 0;
	(*data)->free_me = NULL;
	(*data)->lock_print = NULL;
	(*data)->lock_dinner = NULL;
	return (init_data_mutexes(*data));
}

static int	init_data_mutexes(t_data *data)
{
	data->lock_print = (t_mutex *)ft_lalloc(&data->free_me, sizeof(t_mutex));
	if (!data->lock_print)
		return (-1);
	data->lock_dinner = (t_mutex *)ft_lalloc(&data->free_me, sizeof(t_mutex));
	if (!data->lock_dinner)
	{
		data->lock_print = NULL;
		return (-1);
	}
	pthread_mutex_init(data->lock_print, NULL);
	pthread_mutex_init(data->lock_dinner, NULL);
	return (0);
}
