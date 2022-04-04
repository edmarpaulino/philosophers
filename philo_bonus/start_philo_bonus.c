/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:35:27 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 21:42:12 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	create_philo_process(t_philo *philos);
static void	*waiter(void *ptr);
static void	exit_program(t_philo *philos);

int	start_philo(t_philo *philos)
{
	pthread_t	th;

	pthread_create(&th, NULL, &waiter, philos);
	if (philos->data->times_must_eat == 0)
		return (0);
	if (philos->data->first_timestamp == -1)
		return (-1);
	if (create_philo_process(philos))
		return (-1);
	exit_program(philos);
	pthread_join(th, NULL);
	return (0);
}

static int	create_philo_process(t_philo *philos)
{
	int	i;
	int	arr_len;
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
			philos->data->pid_arr[i] = pid;
			philo_algorithm(&philos[i]);
		}
		i++;
	}
	return (0);
}

static void	*waiter(void *ptr)
{
	t_philo	*philos;
	int		arr_len;
	int		i;

	philos = (t_philo *)ptr;
	arr_len = philos->data->num_of_philos;
	i = 0;
	sem_wait(philos->data->i_am_dead);
	while (i < arr_len)
	{
		if (philos->data->pid_arr[i] != -1)
			kill(philos->data->pid_arr[i], SIGKILL);
		i++;
	}
	destroy_data(philos->data);
	exit(0);
	return (NULL);
}

static void	exit_program(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->num_of_philos)
	{
		sem_wait(philos->data->dinner_is_over);
		i++;
	}
	exit(0);
}
