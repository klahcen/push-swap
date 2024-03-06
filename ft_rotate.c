/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 08:06:43 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 12:37:41 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_lstsize(t_Stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_Stack	*ft_lstlast(t_Stack *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	return (ft_lstlast(lst->next));
}

void	rotate(t_Stack **stack)
{
	t_Stack	*last_node;
	int		len;

	len = ft_lstsize(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	last_node->next->next = NULL;
}

void	ra(t_Stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_Stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}
