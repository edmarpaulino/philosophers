/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:53 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/31 15:29:53 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_data(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	*data;

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
	print_data(data);
	destroy_data(data);
	return (0);
}

static void	print_data(t_data *data)
{
	printf("number of philosophers: %d\n", data->num_of_philos);
	printf("time to die: %d\n", data->time_to_die);
	printf("time to eat: %d\n", data->time_to_eat);
	printf("time to sleep: %d\n", data->time_to_sleep);
	printf("times must eat: %d\n", data->times_must_eat);
	printf("is alone: %s\n", (data->is_alone == 1) ? "true" : "false");
	printf("first stamp: %ld\n", data->first_stamp);
	printf("lock print: %p\n", data->lock_print);
	printf("lock dinner: %p\n", data->lock_dinner);
	printf("free me: %p\n", data->free_me);
}
