/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:50:06 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 14:24:43 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_smol_num(t_Stack *stack_a)
{
	int	smolnum;

	smolnum = stack_a->nbr;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->nbr < smolnum)
			smolnum = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (smolnum);
}

int	find_after_smolnum(t_Stack *stack_a)
{
	int	smolnum;
	int	aftersmolnum;

	smolnum = find_smol_num(stack_a);
	if (stack_a->nbr == smolnum)
		stack_a = stack_a->next;
	aftersmolnum = stack_a->nbr;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->nbr < aftersmolnum && stack_a->nbr != smolnum)
			aftersmolnum = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (aftersmolnum);
}

void	ft_small(t_Stack **a, t_Stack **b)
{
	int	smolnum;
	int	aftersmolnum;

	smolnum = find_smol_num(*a);
	if (ft_lstsize(*a) == 5)
		aftersmolnum = find_after_smolnum(*a);
	else
		aftersmolnum = smolnum;
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->nbr == smolnum || (*a)->nbr == aftersmolnum)
			pb(a, b);
		else
			ra(a);
	}
	ft_sortthree(a, ft_sortarrya(*a));
	if ((*b)->next && (*b)->nbr < (*b)->next->nbr)
		sb(b);
	while (*b)
		pa(b, a);
}

void	ft_fnction(t_Stack *a, t_Stack *b)
{
	t_chunk	chanks;
	int		*arrya;

	arrya = ft_sortarrya(a);
	if (ft_lstsize(a) == 2)
		sa(&a);
	else if (ft_lstsize(a) == 3)
		ft_sortthree(&a, arrya);
	else if (ft_lstsize(a) <= 5)
		ft_small(&a, &b);
	else
		ft_sortstack(&a, &b, arrya, &chanks);
	free(arrya);
	free_stack(&a);
}

int	main(int ac, char **av)
{
	t_Stack	*a;
	t_Stack	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		if (ac == 2 && !av[1][0])
			return (-1);
		else if (ac == 2)
			av = ft_split(av[1], ' ');
		if (*av == NULL)
			ft_error();
		ft_storage(&a, av, ac);
		if (!ft_stack_sorted(a))
			ft_fnction(a, b);
	}
	return (0);
}
