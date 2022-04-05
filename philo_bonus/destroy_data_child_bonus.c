/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data_child_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:23:31 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/04 20:55:43 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	destroy_semaphores(t_data *data);

void	destroy_data_child(t_data *data)
{
	destroy_semaphores(data);
	free(data->pid_array);
	free(data);
}

static void	destroy_semaphores(t_data *data)
{
	if (data->forks != SEM_FAILED)
		sem_close(data->forks);
	if (data->lock_print != SEM_FAILED)
		sem_close(data->lock_print);
	if (data->death != SEM_FAILED)
		sem_close(data->death);
	if (data->dinner_is_over != SEM_FAILED)
		sem_close(data->dinner_is_over);
}
