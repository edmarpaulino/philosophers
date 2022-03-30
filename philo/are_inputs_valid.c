/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_inputs_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:56:09 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/30 15:28:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_num(const char *input);
static int	is_int(const char *input);
static int	is_greater_than_max_int(const char *s_num1, const char *s_num2);

int	are_inputs_valid(char **inputs)
{
	int	i;

	i = 0;
	while (inputs[i] && is_num(inputs[i]) && is_int(inputs[i]))
		i++;
	return (inputs[i] == NULL);
}

static int	is_num(const char *input)
{
	int	i;

	i = 0;
	while (input[i] && ft_isdigit(input[i]))
		i++;
	return (input[i] == '\0');
}

static int	is_int(const char *input)
{
	size_t	len;

	len = ft_strlen((char *)input);
	if (len > 10)
		return (0);
	if (len == 10)
		return (is_greater_than_max_int(input, FT_S_MAX_INT));
	return (1);
}

static int	is_greater_than_max_int(const char *s_num1, const char *s_num2)
{
	int	i;

	i = 0;
	while (s_num1[i] && s_num2[i] && s_num1[i] <= s_num2[i])
		i++;
	return (s_num1[i] == '\0' && s_num2[i] == '\0');
}
