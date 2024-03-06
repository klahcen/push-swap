/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 07:58:44 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 12:38:24 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap(t_Stack **stack)
{
	int	temp;

	if (!stack || !(*stack)->next)
		return ;
	temp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = temp;
}

void	sa(t_Stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_Stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}
