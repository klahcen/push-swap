/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 03:03:36 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 12:40:01 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	swap1(t_Stack **stack_a, t_Stack **stack_b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		swap(stack_a);
	else if (!ft_strcmp(str, "sb\n") && *stack_b)
		swap(stack_b);
	else if (!ft_strcmp(str, "ss\n"))
	{
		swap(stack_a);
		swap(stack_b);
	}
}

void	push1(t_Stack **stack_a, t_Stack **stack_b, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(str, "pb\n"))
		push(stack_a, stack_b);
}

void	rotate1(t_Stack **stack_a, t_Stack **stack_b, char *str)
{
	if (!ft_strcmp(str, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(str, "rb\n"))
		rotate(stack_b);
	else if (!ft_strcmp(str, "rr\n"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}

void	rev_rotate1(t_Stack **stack_a, t_Stack **stack_b, char *str)
{
	if (!ft_strcmp(str, "rra\n"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(str, "rrb\n"))
		reverse_rotate(stack_b);
	else if (!ft_strcmp(str, "rrr\n"))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}

t_Stack	*ft_fill_stack(int ac, char **av)
{
	int		i;
	t_Stack	*stack_a;

	i = 0;
	stack_a = NULL;
	while (i < ac)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	return (stack_a);
}
