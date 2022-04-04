/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_algorithm_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:48:39 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 21:30:16 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief exec actions for one philosopher
 * 
 * @param philo pointer to philosopher struct
 */
static void	go_eat_alone(t_philo *philo);

/**
 * @brief checks if the philosopher died and exit if yes
 * 
 * @param philo pointer to philosopher struct
 */
static void	is_dead(t_philo *philo);

/**
 * @brief exec eat action for philosopher
 * 
 * @param philo pointer to philosopher struct
 */
static void	go_eat(t_philo *philo);

/**
 * @brief exec sleep action for philosopher
 * 
 * @param philo pointer to philosopher struct
 */
static void	go_sleep(t_philo *philo);

void	philo_algorithm(t_philo *philo)
{
	if (philo->number % 2 == 0)
		usleep(5000);
	if (philo->data->is_alone)
		go_eat_alone(philo);
	while (1)
	{
		is_dead(philo);
		go_eat(philo);
		if (philo->total_meals == philo->data->times_must_eat)
			break ;
		go_sleep(philo);
		print_philo_action(philo, PHILO_IS_THINKING);
		usleep(500);
	}
	destroy_data(philo->data);
	exit(0);
}

static void	go_eat_alone(t_philo *philo)
{
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	usleep(philo->data->time_to_die * 1000);
	print_philo_action(philo, PHILO_DIED);
	sem_post(philo->data->dinner_is_over);
	destroy_data(philo->data);
}

static void	is_dead(t_philo *philo)
{
	long	since_last_meal;

	since_last_meal = get_timestamp() - philo->last_meal;
	if (since_last_meal <= philo->data->time_to_die)
		return ;
	print_philo_action(philo, PHILO_DIED);
	sem_post(philo->data->dinner_is_over);
	destroy_data(philo->data);
}

static void	go_eat(t_philo *philo)
{
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	print_philo_action(philo, PHILO_IS_EATING);
	philo->last_meal = get_timestamp();
	usleep(philo->data->time_to_eat);
	philo->total_meals++;
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

static void	go_sleep(t_philo *philo)
{
	long	time_to_sleep_ms;
	long	i;

	time_to_sleep_ms = philo->data->time_to_sleep;
	print_philo_action(philo, PHILO_IS_SLEEPING);
	i = 0;
	while (i < time_to_sleep_ms)
	{
		usleep(1000);
		is_dead(philo);
		i++;
	}
}
