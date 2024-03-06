/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_chekcer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 02:51:51 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 12:39:35 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && (unsigned char)s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_stoi(const char *number)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	if (number[i] == '-' || number[i] == '+')
	{
		if (number[i++] == '-')
			sign *= -1;
		if (number[i] < '0' || number[i] > '9')
			ft_error();
	}
	num = 0;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			ft_error();
		num = num * 10 + (number[i++] - '0');
	}
	if (sign * num <= INT_MIN || sign * num >= INT_MAX)
		ft_error();
	return (sign * num);
}

int	check_which_operation(t_Stack **a, t_Stack **b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		if (!ft_strcmp(op, "pa\n") || !ft_strcmp(op, "pb\n"))
			push1(a, b, op);
		else if (!ft_strcmp(op, "sa\n") || !ft_strcmp(op, "sb\n")
			|| !ft_strcmp(op, "ss\n"))
			swap1(a, b, op);
		else if (!ft_strcmp(op, "ra\n") || !ft_strcmp(op, "rb\n")
			|| !ft_strcmp(op, "rr\n"))
			rotate1(a, b, op);
		else if (!ft_strcmp(op, "rra\n") || !ft_strcmp(op, "rrb\n")
			|| !ft_strcmp(op, "rrr\n"))
			rev_rotate1(a, b, op);
		else
			return (write(2, "Error\n", 6));
		free(op);
		op = get_next_line(0);
	}
	if (ft_stack_sorted(*a) && !(*b))
		return (write(1, "OK\n", 3));
	else
		return (write(1, "KO\n", 3));
}

static	void	valid(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				ft_error();
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_Stack	*a;
	t_Stack	*b;

	b = NULL;
	if (ac <= 2)
		return (0);
	valid(ac, av);
	a = ft_fill_stack(ac - 1, av + 1);
	check_which_operation(&a, &b);
	return (0);
}
