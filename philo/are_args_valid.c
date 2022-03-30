/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_args_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:56:09 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/30 18:46:37 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_num(const char *arg);
static int	is_int(const char *arg);
static int	is_greater_than_max_int(const char *s_num1, const char *s_num2);

int	are_args_valid(const int argc, const char **argv)
{
	int	i;

	if ((argc != 5 && argc != 6))
		return (0);
	i = 1;
	while (argv[i] && is_num(argv[i]) && is_int(argv[i]))
		i++;
	return (argv[i] == NULL);
}

static int	is_num(const char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	return (arg[i] == '\0');
}

static int	is_int(const char *arg)
{
	size_t	len;

	len = ft_strlen((char *)arg);
	if (len > 10)
		return (0);
	if (len == 10)
		return (is_greater_than_max_int(arg, FT_STR_MAX_INT));
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
