/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:23:31 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/05 08:51:18 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	destroy_semaphores(t_data *data);

void	destroy_data(t_data *data)
{
	destroy_semaphores(data);
	free(data->pid_array);
	free(data);
}

static void	destroy_semaphores(t_data *data)
{
	sem_unlink(SEM_FORKS_NAME);
	sem_unlink(SEM_LOCK_PRINT_NAME);
	sem_unlink(SEM_DEATH_NAME);
	sem_unlink(SEM_DINNER_IS_OVER_NAME);
	if (data->forks != SEM_FAILED)
		sem_close(data->forks);
	if (data->lock_print != SEM_FAILED)
		sem_close(data->lock_print);
	if (data->death != SEM_FAILED)
		sem_close(data->death);
	if (data->dinner_is_over != SEM_FAILED)
		sem_close(data->dinner_is_over);
}
