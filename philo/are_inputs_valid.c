/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_inputs_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:56:09 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/27 20:06:21 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_num(char *input);
int	is_int(char *input);

int	are_inputs_valid(char **inputs)
{
	int	i;

	i = 0;
	while (inputs[i])
	{
		if (!is_num(inputs[i]) || !is_int(inputs[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_num(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_int(char *input)
{
	return (ft_strlen(input) <= 10 && ft_atoui(input) <= FT_MAX_INT);
}
