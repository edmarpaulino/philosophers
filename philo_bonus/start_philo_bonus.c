/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:35:27 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 12:03:39 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	create_philo_process(t_philo *philos, int *pid_arr);
static int	wait_philo_process(t_philo *philos, int *pid_arr);
static void	print_child(t_philo *philo);
static void	kill_all_philosophers(int n, int *pid_arr);

int	start_philo(t_philo *philos)
{
	int		*pid_arr;
	t_data	*data;

	if (philos[0].data->times_must_eat == 0)
		return (0);
	philos[0].data->first_timestamp = get_timestamp();
	if (philos[0].data->first_timestamp == -1)
		return (-1);
	data = philos[0].data;
	pid_arr = (int *)ft_lalloc(&data->free_me, sizeof(int) * data->num_of_philos);
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

	arr_len = philos[0].data->num_of_philos;
	i = 0;
	while (i < arr_len)
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			philos[i].pid = pid;
			print_child(&philos[i]);
			destroy_data(philos[i].data);
			exit(0);
		}
		pid_arr[i] = pid;
		i++;
	}
	return (0);
}

static int	wait_philo_process(t_philo *philos, int *pid_arr)
{
	int	arr_len;
	int	i;
	int	status;

	arr_len = philos[0].data->num_of_philos;
	i = 0;
	while (i < arr_len)
	{
		waitpid(pid_arr[i], &status, 0);
		if (status)
		{
			kill_all_philosophers(arr_len, pid_arr);
			destroy_data(philos[0].data);
			exit (-1);
		}
		i++;
	}
	return (0);
}

static void	print_child(t_philo *philo)
{
	printf("I'm the philosopher %d\n", philo->number);
	if (philo->number == 7)
		exit(2);
	return ;
}

static void	kill_all_philosophers(int arr_len, int *pid_arr)
{
	int	i;

	i = 0;
	while (i < arr_len)
	{
		kill(pid_arr[i], SIGKILL);
		i++;
	}
}
