/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_arrya.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:48:32 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 12:37:48 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static	int	*ft_sortarrya1(t_Stack *a)
{
	int	*arrya;
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(a);
	arrya = (int *)malloc((sizeof(int) * size));
	if (!arrya)
		return (NULL);
	while (a)
	{
		arrya[i] = a->nbr;
		i++;
		a = a->next;
	}
	return (arrya);
}

int	*ft_sortarrya(t_Stack *a)
{
	int	*arrya;
	int	i;
	int	j;
	int	size;
	int	tmp;

	i = 1;
	size = ft_lstsize(a);
	arrya = ft_sortarrya1(a);
	while (i < size)
	{
		j = 0;
		while (i > j)
		{
			if (arrya[i] < arrya[j])
			{
				tmp = arrya[i];
				arrya[i] = arrya[j];
				arrya[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arrya);
}
