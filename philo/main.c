/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:53 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/31 17:33:06 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_data(t_data *data);
static void	print_philos(t_philo *philos);

int	main(int argc, char *argv[])
{
	t_data	*data;
	t_philo	*philos;

	if (!are_args_valid((const int)argc, (const char **)argv))
	{
		printf(RED "Error: Invalid arguments\n" RESET);
		return (1);
	}
	printf(GREEN "All inputs are valid\n" RESET);
	if (init_data(argc, argv, &data))
	{
		printf(RED "Error: Failed to create data structure\n" RESET);
		destroy_data(data);
		return (3);
	}
	if (init_philos(&philos, data))
	{
		printf(RED "Error: Failed to create philosophers array\n" RESET);
		destroy_data(data);
		return (4);
	}
	print_data(data);
	print_philos(philos);
	destroy_philos(philos);
	return (0);
}

static void	print_data(t_data *data)
{
	printf("number of philosophers: %d\n", data->num_of_philos);
	printf("time to die: %d\n", data->time_to_die);
	printf("time to eat: %d\n", data->time_to_eat);
	printf("time to sleep: %d\n", data->time_to_sleep);
	printf("times must eat: %d\n", data->times_must_eat);
	if (data->is_alone)
		printf("is alone: true\n");
	else
		printf("is alone: false\n");
	printf("first stamp: %ld\n", data->first_stamp);
	printf("forks array: %p\n", data->forks);
	printf("free me: %p\n", data->free_me);
}

static void	print_philos(t_philo *philos)
{
	int	i;
	int	arr_len;

	i = 0;
	arr_len = philos[0].data->num_of_philos;
	while (i < arr_len)
	{
		printf("============================\n");
		printf("philo number: %d\n", philos[i].philo_number);
		printf("meal counter: %d\n", philos[i].meal_counter);
		printf("last meal: %ld\n", philos[i].last_meal);
		printf("right fork: %p\n", philos[i].right_fork);
		printf("left fork: %p\n", philos[i].left_fork);
		printf("data pointer: %p\n", philos[i].data);
		i++;
	}
}
