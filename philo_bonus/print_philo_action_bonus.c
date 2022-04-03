/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_action_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:10:47 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 16:20:57 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_philo_action(t_philo *philo, int action_code)
{
	long	timestamp;

	sem_wait(philo->data->lock_print);
	timestamp = get_timestamp() - philo->data->first_timestamp;
	if (action_code == PHILO_TAKEN_A_FORK)
		printf("%5ld %3d has taken a fork\n", timestamp, philo->number);
	else if (action_code == PHILO_IS_EATING)
		printf("%5ld %3d is eating\n", timestamp, philo->number);
	else if (action_code == PHILO_IS_SLEEPING)
		printf("%5ld %3d is sleeping\n", timestamp, philo->number);
	else if (action_code == PHILO_IS_THINKING)
		printf("%5ld %3d is thinking\n", timestamp, philo->number);
	else if (action_code == PHILO_DIED)
		printf(RED "%5ld %3d died" RESET, timestamp, philo->number);
	if (action_code != PHILO_DIED)
		sem_post(philo->data->lock_print);
}
