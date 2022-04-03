/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:21:20 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 17:22:25 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief init data semaphores and before init unlink semaphores
 * to avoid errors if the semphores already exists
 * 
 * @param data data structure pointer
 * @return int 0 on success or -1 on failure
 */
static int	init_data_semaphores(t_data *data);

int	init_data(int argc, char **argv, t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
		return (-1);
	(*data)->num_of_philos = ft_atoi(argv[NUM_OF_PHILOS]);
	(*data)->time_to_die = ft_atoi(argv[TIME_TO_DIE]);
	(*data)->time_to_eat = ft_atoi(argv[TIME_TO_EAT]) * 1000;
	(*data)->time_to_sleep = ft_atoi(argv[TIME_TO_SLEEP]);
	(*data)->times_must_eat = -1;
	if (argc == 6)
		(*data)->times_must_eat = ft_atoi(argv[TIMES_MUST_EAT]);
	(*data)->is_alone = ((*data)->num_of_philos == 1);
	(*data)->first_timestamp = get_timestamp();
	(*data)->free_me = NULL;
	return (init_data_semaphores(*data));
}

static int	init_data_semaphores(t_data *data)
{
	sem_unlink(SEM_FORKS_NAME);
	sem_unlink(SEM_LOCK_PRINT_NAME);
	sem_unlink(SEM_DINNER_IS_OVER_NAME);
	data->forks = SEM_FAILED;
	data->lock_print = SEM_FAILED;
	data->forks = sem_open(SEM_FORKS_NAME, O_CREAT, 0600, data->num_of_philos);
	if (data->forks == SEM_FAILED)
		return (-1);
	data->lock_print = sem_open(SEM_LOCK_PRINT_NAME, O_CREAT, 0600, 1);
	if (data->lock_print == SEM_FAILED)
		return (-1);
	return (0);
}
