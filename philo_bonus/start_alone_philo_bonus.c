/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_alone_philo_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:15:28 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/04 21:46:25 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	go_eat_alone(t_philo *philos);

int	start_alone_philo(t_philo *philos)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		go_eat_alone(philos);
	waitpid(-1, NULL, 0);
	return (0);
}

static void	go_eat_alone(t_philo *philos)
{
	print_philo_action(&philos[0], PHILO_TAKEN_A_FORK);
	usleep(philos->data->time_to_die * 1000);
	print_philo_action(&philos[0], PHILO_DIED);
	destroy_philos_child(philos);
	exit(0);
}
