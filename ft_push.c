/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:02:05 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 12:36:55 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_Stack	*ft_lstnew(long content)
{
	t_Stack	*new;

	new = malloc(sizeof(t_Stack));
	if (new == NULL)
		return (NULL);
	new->nbr = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_Stack **lst, t_Stack *new)
{
	t_Stack	*p;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			new->next = NULL;
			return ;
		}
		p = ft_lstlast(*lst);
		p->next = new;
	}
}

void	push(t_Stack **source, t_Stack **destination)
{
	t_Stack	*node_to_push;

	if (NULL == *source)
		return ;
	node_to_push = *source;
	*source = (*source)->next;
	if (NULL == *destination)
	{
		*destination = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *destination;
		*destination = node_to_push;
	}
}

void	pb(t_Stack **a, t_Stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_Stack **b, t_Stack **a)
{
	push(b, a);
	write(1, "pa\n", 3);
}
