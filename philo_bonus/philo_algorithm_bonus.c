/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_algorithm_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:48:39 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 15:35:26 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	go_eat(t_philo *philo);

void	philo_algorithm(t_philo *philo)
{
	if (philo->number % 2 == 0)
		usleep(1000);
	while (1)
	{
		go_eat(philo);
		if (philo->total_meals == philo->data->times_must_eat)
			break ;
		print_philo_action(philo, PHILO_IS_SLEEPING);
		usleep(philo->data->time_to_sleep);
		print_philo_action(philo, PHILO_IS_THINKING);
		usleep(500);
	}
	destroy_data(philo->data);
	exit(0);
}

static void	go_eat(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	sem_wait(philo->data->forks);
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	print_philo_action(philo, PHILO_IS_EATING);
	philo->last_meal = get_timestamp();
	usleep(philo->data->time_to_eat);
	philo->total_meals++;
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}
