/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:20:35 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/31 15:29:59 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_data(t_data *data)
{
	if (!data)
		return ;
	if (data->lock_print)
		pthread_mutex_destroy(data->lock_print);
	if (data->lock_dinner)
		pthread_mutex_destroy(data->lock_dinner);
	ft_lfree(data->free_me);
	free(data);
}
