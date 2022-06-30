/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:21:32 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/02 10:17:54 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp(void)
{
	struct timeval	cur_time;

	if (gettimeofday(&cur_time, NULL))
		return (-1);
	return ((cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000));
}
