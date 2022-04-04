/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_algorithm_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:48:39 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/04 11:20:20 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	go_eat_alone(t_philo *philo);
static void	is_dead(t_philo *philo);
static void	go_eat(t_philo *philo);
static void	go_sleep(t_philo *philo);

void	philo_algorithm(t_philo *philo)
{
	sem_t	*finish_dinner;

	if (philo->data->is_alone)
		go_eat_alone(philo);
	if (philo->number % 2 == 0)
		usleep(1000);
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
	finish_dinner = philo->data->dinner_is_over;
	destroy_data(philo->data, 0);
	sem_post(finish_dinner);
	exit(0);
}

static void	go_eat_alone(t_philo *philo)
{
	sem_t	*i_died;

	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	usleep(philo->data->time_to_die * 1000);
	print_philo_action(philo, PHILO_DIED);
	i_died = philo->data->i_died;
	destroy_data(philo->data, 0);
	sem_post(i_died);
}

static void	is_dead(t_philo *philo)
{
	long	since_last_meal;
	sem_t	*i_died;

	since_last_meal = get_timestamp() - philo->last_meal;
	if (since_last_meal <= philo->data->time_to_die)
		return ;
	print_philo_action(philo, PHILO_DIED);
	i_died = philo->data->i_died;
	destroy_data(philo->data, 0);
	sem_post(i_died);
}

static void	go_eat(t_philo *philo)
{
	int	i;

	sem_wait(philo->data->forks);
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	sem_wait(philo->data->forks);
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	print_philo_action(philo, PHILO_IS_EATING);
	philo->last_meal = get_timestamp();
	i = 0;
	while (i < philo->data->time_to_eat)
	{
		usleep(1000);
		is_dead(philo);
		i++;
	}
	philo->total_meals++;
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

static void	go_sleep(t_philo *philo)
{
	int	i;

	print_philo_action(philo, PHILO_IS_SLEEPING);
	i = 0;
	while (i < philo->data->time_to_sleep)
	{
		usleep(1000);
		is_dead(philo);
		i++;
	}
}
