/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:06:14 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/05 08:50:31 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	init_simple_data(const int argc, const char **argv, t_data *data);
static void	init_pid_array(int *pid_array, int size);
static int	init_data_semaphores(t_data *data);

t_data	*get_data(const int argc, const char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	init_simple_data(argc, argv, data);
	data->pid_array = (int *)malloc(data->num_of_philos * sizeof(int));
	if (!data->pid_array)
	{
		free(data);
		return (NULL);
	}
	init_pid_array(data->pid_array, data->num_of_philos);
	if (init_data_semaphores(data))
	{
		free(data->pid_array);
		free(data);
		return (NULL);
	}
	return (data);
}

static void	init_simple_data(const int argc, const char **argv, t_data *data)
{
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->times_must_eat = -1;
	if (argc == 6)
		data->times_must_eat = ft_atoi(argv[5]);
	data->first_timestamp = get_timestamp();
}

static void	init_pid_array(int *pid_array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pid_array[i] = -1;
		i++;
	}
}

static int	init_data_semaphores(t_data *data)
{
	sem_unlink(SEM_FORKS_NAME);
	sem_unlink(SEM_LOCK_PRINT_NAME);
	sem_unlink(SEM_DEATH_NAME);
	sem_unlink(SEM_DINNER_IS_OVER_NAME);
	data->forks = SEM_FAILED;
	data->lock_print = SEM_FAILED;
	data->death = SEM_FAILED;
	data->dinner_is_over = SEM_FAILED;
	data->forks = sem_open(SEM_FORKS_NAME, O_CREAT, 0600, data->num_of_philos);
	if (data->forks == SEM_FAILED)
		return (-1);
	data->lock_print = sem_open(SEM_LOCK_PRINT_NAME, O_CREAT, 0600, 1);
	if (data->lock_print == SEM_FAILED)
		return (-1);
	data->death = sem_open(SEM_DEATH_NAME, O_CREAT, 0600, 0);
	if (data->death == SEM_FAILED)
		return (-1);
	data->dinner_is_over = sem_open(SEM_DINNER_IS_OVER_NAME, O_CREAT, 0600, 0);
	if (data->dinner_is_over == SEM_FAILED)
		return (-1);
	return (0);
}
