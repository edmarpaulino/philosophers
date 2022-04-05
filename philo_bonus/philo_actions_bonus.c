/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:09:55 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/05 11:19:02 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	go_eat(t_philo *philo);
static void	go_sleep(t_philo *philo);
static void	go_think(t_philo *philo);
static void	check_life(t_philo *philo);

void	philo_actions(t_philo *philo)
{
	if (philo->num % 2 == 0)
		usleep(5000);
	while (1)
	{
		go_eat(philo);
		if (philo->num_of_meals == philo->data->times_must_eat)
		{
			sem_post(philo->data->dinner_is_over);
			return ;
		}
		go_sleep(philo);
		go_think(philo);
	}
}

static void	go_eat(t_philo *philo)
{
	long	start_time;

	sem_wait(philo->data->forks);
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	sem_wait(philo->data->forks);
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	print_philo_action(philo, PHILO_IS_EATING);
	philo->last_meal_timestamp = get_timestamp();
	start_time = get_timestamp();
	while ((get_timestamp() - start_time) < philo->data->time_to_eat)
		check_life(philo);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	philo->num_of_meals++;
}

static void	go_sleep(t_philo *philo)
{
	long	start_time;

	print_philo_action(philo, PHILO_IS_SLEEPING);
	start_time = get_timestamp();
	while ((get_timestamp() - start_time) < philo->data->time_to_sleep)
		check_life(philo);
}

static void	go_think(t_philo *philo)
{
	print_philo_action(philo, PHILO_IS_THINKING);
	while (*(int *)philo->data->forks < 2)
		check_life(philo);
}

static void	check_life(t_philo *philo)
{
	long	timestamp;

	timestamp = get_timestamp() - philo->last_meal_timestamp;
	if (timestamp > philo->data->time_to_die)
	{
		print_philo_action(philo, PHILO_DIED);
		sem_post(philo->data->death);
	}
	usleep(500);
}
