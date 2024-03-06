/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:55:09 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/26 00:05:15 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sin;
	long	resl;
	int		s;

	i = 0;
	s = 0;
	sin = 1;
	resl = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while ((str[i] == '+' || str[i] == '-') && s == 0)
	{
		if (str[i] == '-')
			sin *= -1;
		i++;
		s++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resl = resl * 10 + (str[i] - 48);
		i++;
	}
	return (resl * sin);
}
