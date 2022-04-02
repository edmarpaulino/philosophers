/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:17:57 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/01 20:58:45 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief 
 * 
 * @param philo 
 * @return int 
 */
static int	dinner_is_over(t_philo *philo);

/**
 * @brief 
 * 
 * @param philo 
 */
static void	go_eat(t_philo *philo);

/**
 * @brief 
 * 
 * @param philo 
 */
static void	go_eat(t_philo *philo);

/**
 * @brief 
 * 
 * @param philo 
 */
static void	go_sleep(t_philo *philo);

/**
 * @brief 
 * 
 * @param philo 
 */
static void	go_thinking(t_philo *philo);

void	*philo_algorithm(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (ft_iseven(philo->number))
		usleep(700);
	if (philo->data->is_alone)
	{
		go_eat_alone(philo);
		return (NULL);
	}
	while (!dinner_is_over(philo))
	{
		go_eat(philo);
		go_sleep(philo);
		pthread_mutex_lock(&philo->lock_total_meals);
		if (philo->total_meals == philo->data->times_must_eat)
		{
			pthread_mutex_unlock(&philo->lock_total_meals);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->lock_total_meals);
		go_thinking(philo);
	}
	return (NULL);
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
	pthread_mutex_lock(philo->left_fork);
	if (dinner_is_over(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	print_philo_action(philo, PHILO_TAKEN_A_FORK);
	print_philo_action(philo, PHILO_IS_EATING);
	pthread_mutex_lock(&philo->lock_last_meal);
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&philo->lock_last_meal);
	usleep(milli_to_micro(philo->data->time_to_eat));
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	philo->total_meals++;
}

static void	go_sleep(t_philo *philo)
{
	print_philo_action(philo, PHILO_IS_SLEEPING);
	usleep(milli_to_micro(philo->data->time_to_sleep));
}

static void	go_thinking(t_philo *philo)
{
	print_philo_action(philo, PHILO_IS_THINKING);
	usleep(500);
}
