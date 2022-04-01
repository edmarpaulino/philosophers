/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_converters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:46:32 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/01 14:48:19 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	micro_to_milli(long usec)
{
	return (usec / ONE_THOUSAND);
}

long	milli_to_micro(long msec)
{
	return (msec * ONE_THOUSAND);
}

long	sec_to_micro(long sec)
{
	return (sec * ONE_MILLION);
}
