/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:44:40 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/27 20:16:15 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	ft_atoui(char *str)
{
	unsigned int	ui;
	int				i;

	ui = 0;
	if (!str)
		return (ui);
	i = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	while (ft_isdigit(str[i]) && str[i])
	{
		ui = (ui * 10) + (str[i] - '0');
		i++;
	}
	return (ui);
}
