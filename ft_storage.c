/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:07:15 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 12:38:11 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stack(t_Stack **a, long nbr)
{
	ft_lstadd_back(a, ft_lstnew(nbr));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_storage(t_Stack **a, char **av, int ac)
{
	long	nbr;
	int		i;

	i = 0;
	if (ac > 2)
		i = 1;
	while (av[i])
	{
		if (error_syntax(av[i]) || ft_strlen(av[i]) > 11)
			error_free(a, av, ac);
		nbr = ft_atoi(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av, ac);
		if (error_repetition(*a, (int)nbr))
			error_free(a, av, ac);
		ft_stack(a, nbr);
		i++;
	}
	if (ac == 2)
		free_matrix(av);
}
