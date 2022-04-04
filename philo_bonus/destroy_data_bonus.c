/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:37:33 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/04 09:59:12 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	destroy_semaphore(sem_t *sem, char *sem_name);

void	destroy_data(t_data *data, int sem)
{
	if (!data)
		return ;
	if (sem)
	{
		destroy_semaphore(data->forks, SEM_FORKS_NAME);
		destroy_semaphore(data->lock_print, SEM_LOCK_PRINT_NAME);
		destroy_semaphore(data->dinner_is_over, SEM_DINNER_IS_OVER_NAME);
		destroy_semaphore(data->i_died, SEM_I_DIED_NAME);
	}
	ft_lfree(data->free_me);
	free(data);
}

static void	destroy_semaphore(sem_t *sem, char *sem_name)
{
	if (sem == SEM_FAILED)
		return ;
	sem_unlink(sem_name);
	sem_close(sem);
}
