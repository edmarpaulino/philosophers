/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:17:57 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/03 16:04:11 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief function when have only one philosopher to execute their actions
 * 
 * @param philo philosophers array - in this case with one element
 */
static void	go_eat_alone(t_philo *philo);

/**
 * @brief checks if the dinner is over
 * 
 * @param philo pointer to philosopher struct
 * @return int 1 if is over or 0 if is not
 */
static int	dinner_is_over(t_philo *philo);

/**
 * @brief eat action for philosopher
 * 
 * @param philo pointer to philosopher struct
 */
static void	go_eat(t_philo *philo);

void	*philo_algorithm(void *ptr)
{
	t_philo	*philo;
	int		total_meals;

	philo = (t_philo *)ptr;
	if (philo->number % 2 == 0)
		usleep(700);
	if (philo->data->is_alone)
	{
		go_eat_alone(philo);
		return (NULL);
	}
	while (!dinner_is_over(philo))
	{
		go_eat(philo);
		pthread_mutex_lock(&philo->lock_total_meals);
		total_meals = philo->total_meals;
		pthread_mutex_unlock(&philo->lock_total_meals);
		if (total_meals == philo->data->times_must_eat)
			return (NULL);
		print_philo_action(philo, PHILO_IS_SLEEPING);
		usleep(philo->data->time_to_sleep);
		print_philo_action(philo, PHILO_IS_THINKING);
		usleep(500);
	}
	return (NULL);
}

static void	go_eat_alone(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	pthread_mutex_unlock(philo->right_fork);
}

static int	dinner_is_over(t_philo *philo)
{
	int	is_over;

	is_over = 0;
	pthread_mutex_lock(&philo->data->lock_dinner);
	is_over = philo->data->dinner_is_over;
	pthread_mutex_unlock(&philo->data->lock_dinner);
	return (is_over);
}

static void	go_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	pthread_mutex_lock(philo->left_fork);
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	if (dinner_is_over(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	print_philo_action(philo, PHILO_IS_EATING);
	pthread_mutex_lock(&philo->lock_last_meal);
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&philo->lock_last_meal);
	usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->lock_total_meals);
	philo->total_meals++;
	pthread_mutex_unlock(&philo->lock_total_meals);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
