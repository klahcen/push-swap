/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:25:59 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 12:34:56 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_matrix(char **av)
{
	int	i;

	i = 0;
	if (NULL == av || NULL == *av)
		return ;
	while (av[i])
	{
		free(av[i++]);
	}
	free(av);
}

void	free_stack(t_Stack **stack)
{
	t_Stack	*tmp;
	t_Stack	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	error_syntax(char *av)
{
	if (!(*av == '+' || *av == '-' || (*av >= '0' && *av <= '9')))
		return (1);
	if ((*av == '+' || *av == '-') && !(av[1] >= '0' && av[1] <= '9'))
		return (1);
	while (*++av)
	{
		if (!(*av >= '0' && *av <= '9'))
			return (1);
	}
	return (0);
}

void	error_free(t_Stack **a, char **av, int ac)
{
	free_stack(a);
	if (ac == 2)
		free_matrix(av);
	ft_error();
}

int	error_repetition(t_Stack *a, int nbr)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->nbr == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
