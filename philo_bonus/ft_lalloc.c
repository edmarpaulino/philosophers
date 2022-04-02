/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:04:14 by edpaulin          #+#    #+#             */
/*   Updated: 2022/04/02 15:26:58 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_list	*ft_lstnew(void *content);
static void		ft_lstadd_front(t_list **list, t_list *new);

void	*ft_lalloc(t_list **list, size_t alloc_size)
{
	t_list	*new;
	void	*ptr;

	ptr = (void *)malloc(alloc_size);
	new = ft_lstnew(ptr);
	if (!new)
	{
		free(ptr);
		return (NULL);
	}
	ft_lstadd_front(list, new);
	return (ptr);
}

static t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

static void	ft_lstadd_front(t_list **list, t_list *new)
{
	t_list	*aux;

	if (!list || !new)
		return ;
	aux = *list;
	*list = new;
	(*list)->next = aux;
}
