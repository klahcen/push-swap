/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 08:18:26 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 12:37:18 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_lstadd_front(t_Stack **lst, t_Stack *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	reverse_rotate(t_Stack **stack)
{
	t_Stack	*lastnode;
	t_Stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	lastnode = ft_lstlast(*stack);
	tmp = *stack;
	while (tmp->next != lastnode)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	ft_lstadd_front(stack, lastnode);
}

void	rra(t_Stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_Stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_Stack **a, t_Stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
