/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 06:26:19 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 12:36:45 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_sortthree(t_Stack **a, int *array)
{
	if ((*a)->nbr == array[2])
		ra(a);
	else if ((*a)->next->nbr == array[2])
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	check_cases(t_Stack **a, t_Stack **b, int *arrya, t_chunk *chanks)
{
	if ((*b)->nbr == arrya[chanks->max])
	{
		pa(b, a);
		(chanks->max)--;
		if ((*a)->next && (*a)->nbr > (*a)->next->nbr)
		{
			sa(a);
			(chanks->max)--;
		}
	}
	else if ((*b)->nbr == arrya[chanks->max - 1])
		pa(b, a);
	else
		not_max_num(a, b, chanks);
}

int	find_big_num_index(t_Stack *stack, int max)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->nbr == max)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	not_max_num(t_Stack **a, t_Stack **b, t_chunk *chanks)
{
	if (chanks->k == 0
		|| (*b)->nbr > ft_lstlast(*a)->nbr)
	{
		pa(b, a);
		ra(a);
		(chanks->k)++;
	}
	else
	{
		if (find_big_num_index(*b, big_num(*b)) < ft_lstsize(*b) / 2)
			rb(b);
		else
			rrb(b);
	}
}
