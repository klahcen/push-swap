/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:20:32 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 12:35:25 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	big_num(t_Stack *stack)
{
	int	bignum;

	bignum = stack->nbr;
	stack = stack->next;
	while (stack)
	{
		if (stack->nbr > bignum)
			bignum = stack->nbr;
		stack = stack->next;
	}
	return (bignum);
}

void	check_case2(t_Stack **a, t_chunk *chanks)
{
	if (chanks->k > 0)
	{
		rra(a);
		(chanks->k)--;
		(chanks->max)--;
	}
}

void	ft_a_to_b(t_Stack **a, t_Stack **b, int *arrya, t_chunk *chanks)
{
	while (*a)
	{
		if (ft_lstsize(*a) == 1)
			pb(a, b);
		while (ft_lstsize(*b) < chanks->end - chanks->start)
		{
			if (!((*a)->nbr < arrya[chanks->end]
					&& (*a)->nbr >= arrya[chanks->start]))
				ra(a);
			else
			{
				pb(a, b);
				if ((*b)->nbr < arrya[chanks->mid])
					rb(b);
			}
		}
		chanks->start -= chanks->offset;
		if (chanks->start < 0)
			chanks->start = 0;
		chanks->end += chanks->offset;
		if (chanks->end >= chanks->size)
			chanks->end = chanks->size - 1;
	}
}

void	ft_b_to_a(t_Stack **a, t_Stack **b, int *arrya, t_chunk *chanks)
{
	chanks->k = 0;
	chanks->max = ft_lstsize(*b) - 1;
	while (*b)
	{
		if ((*b) && big_num(*b) == arrya[chanks->max])
			check_cases(a, b, arrya, chanks);
		else
			check_case2(a, chanks);
	}
	while (chanks->k != 0)
	{
		rra(a);
		chanks->k--;
	}
}
