/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:45:36 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 12:38:03 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	num_chunk(int *size, int *n)
{
	if (*size <= 30)
		*n = 5;
	else if (*size <= 150)
		*n = 8;
	else
		*n = 18;
}

void	ft_sortstack(t_Stack **a, t_Stack **b, int *arrya, t_chunk *chanks)
{
	chanks->size = ft_lstsize(*a);
	chanks->mid = (chanks->size / 2);
	num_chunk(&chanks->size, &chanks->i);
	chanks->offset = (chanks->size / chanks->i);
	chanks->start = chanks->mid - chanks->offset;
	chanks->end = chanks->mid + chanks->offset;
	ft_a_to_b(a, b, arrya, chanks);
	ft_b_to_a(a, b, arrya, chanks);
}
