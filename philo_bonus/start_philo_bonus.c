/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:35:27 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 18:22:46 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	create_philo_process(t_philo *philos, int *pid_arr);
static int	wait_philo_process(t_philo *philos, int *pid_arr);
static void	kill_all_philosophers(int *pid_arr, int arr_len);

int	start_philo(t_philo *philos)
{
	int		*pid_arr;
	t_data	*data;
	size_t	arr_size;

	if (philos->data->times_must_eat == 0)
		return (0);
	if (philos->data->first_timestamp == -1)
		return (-1);
	data = philos->data;
	arr_size = sizeof(int) * data->num_of_philos;
	pid_arr = (int *)ft_lalloc(&data->free_me, arr_size);
	if (create_philo_process(philos, pid_arr))
		return (-1);
	if (wait_philo_process(philos, pid_arr))
		return (-1);
	return (0);
}

static int	create_philo_process(t_philo *philos, int *pid_arr)
{
	int	arr_len;
	int	i;
	int	pid;

	arr_len = philos->data->num_of_philos;
	i = 0;
	while (i < arr_len)
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			philos[i].pid = pid;
			philo_algorithm(&philos[i]);
		}
		pid_arr[i] = pid;
		i++;
	}
	return (0);
}

static int	wait_philo_process(t_philo *philos, int *pid_arr)
{
	int	status;
	int	i;
	int	arr_len;

	i = 0;
	arr_len = philos->data->num_of_philos;
	while (i < arr_len)
	{
		waitpid(pid_arr[i], &status, 0);
		if (WEXITSTATUS(status))
		{
			kill_all_philosophers(pid_arr, arr_len);
			return (0);
		}
		i++;
	}
	return (0);
}

static void	kill_all_philosophers(int *pid_arr, int arr_len)
{
	int	i;

	i = 0;
	while (i < arr_len)
	{
		kill(pid_arr[i], SIGKILL);
		i++;
	}
}
