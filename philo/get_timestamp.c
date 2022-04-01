/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:21:32 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/01 14:56:17 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp(void)
{
	struct timeval	cur_time;
	long			microseconds;
	long			milliseconds;

	if (gettimeofday(&cur_time, NULL))
		return (-1);
	microseconds = sec_to_micro(cur_time.tv_sec) + cur_time.tv_usec;
	milliseconds = micro_to_milli(microseconds);
	return (milliseconds);
}
