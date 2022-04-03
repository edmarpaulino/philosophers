/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:15:11 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 11:15:34 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_timestamp(void)
{
	struct timeval	cur_time;

	if (gettimeofday(&cur_time, NULL))
		return (-1);
	return ((cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000));
}
