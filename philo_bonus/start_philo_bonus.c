/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:13:41 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/04 21:34:32 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	create_child_process(t_philo *philos);
static void	*reaper(void *ptr);

int	start_philo_bonus(t_philo *philos)
{
	pthread_t	thread_reaper;
	int			i;

	if (pthread_create(&thread_reaper, NULL, &reaper, philos))
		return (-1);
	pthread_detach(thread_reaper);
	if (create_child_process(philos))
		return (-1);
	i = 0;
	while (i < philos->data->num_of_philos)
	{
		sem_wait(philos->data->dinner_is_over);
		i++;
	}
	return (0);
}

static int	create_child_process(t_philo *philos)
{
	int	i;
	int	pid;

	i = 0;
	while (i < philos->data->num_of_philos)
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			philos->data->pid_array[i] = pid;
			philo_actions(&philos[i]);
			destroy_philos_child(philos);
		}
		i++;
	}
	return (0);
}

static void	*reaper(void *ptr)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ptr;
	sem_wait(philos->data->death);
	i = 0;
	while (i < philos->data->num_of_philos)
	{
		if (philos->data->pid_array[i] != -1)
			kill(philos->data->pid_array[i], SIGKILL);
		i++;
	}
	i = 0;
	while (i < philos->data->num_of_philos)
	{
		sem_post(philos->data->dinner_is_over);
		i++;
	}
	return (NULL);
}
