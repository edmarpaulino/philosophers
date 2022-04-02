/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_alone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:14:22 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/01 20:17:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	go_eat_alone(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	pthread_mutex_unlock(philo->right_fork);
}
