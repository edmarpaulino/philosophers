/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:04:29 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/30 19:28:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lfree(t_list *list)
{
	t_list	*aux;

	while (list)
	{
		if (list->content)
			free(list->content);
		aux = list;
		list = list->next;
		free(aux);
	}
}
