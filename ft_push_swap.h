/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkazaz <lkazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:50:48 by lkazaz            #+#    #+#             */
/*   Updated: 2023/12/28 14:29:20 by lkazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "ft_checker/get_next_line.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node
{
	int				nbr;
	struct t_node	*next;
}					t_Stack;

typedef struct t_chunk
{
	int				i;
	int				size;
	int				mid;
	int				offset;
	int				start;
	int				end;
	int				k;
	int				max;
}					t_chunk;

int					ft_strlen(char *str);
void				ft_error(void);
t_Stack				*ft_lstnew(long content);
void				rotate(t_Stack **stack);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_a_to_b(t_Stack **a, t_Stack **b, int *arrya,
						t_chunk *chanks);
void				ft_b_to_a(t_Stack **a, t_Stack **b, int *arrya,
						t_chunk *chanks);
void				check_cases(t_Stack **a, t_Stack **b, int *arrya,
						t_chunk *chanks);
int					big_num(t_Stack *stack);
void				not_max_num(t_Stack **a, t_Stack **b, t_chunk *chanks);
void				ft_lstadd_back(t_Stack **lst, t_Stack *new);
int					ft_lstsize(t_Stack *lst);
t_Stack				*ft_lstlast(t_Stack *lst);
void				ft_putstr(char *str);
int					ft_stack_sorted(t_Stack *stack);
char				**ft_split(char const *s, char c);
long				ft_atoi(const char *str);
void				ft_storage(t_Stack **a, char **av, int ac);
void				ft_stack(t_Stack **a, long nbr);
int					error_syntax(char *av);
void				error_free(t_Stack **a, char **av, int ac);
void				free_stack(t_Stack **stack);
void				free_matrix(char **av);
int					error_repetition(t_Stack *a, int nbr);
void				push(t_Stack **source, t_Stack **destination);
void				rotate(t_Stack **stack);
void				reverse_rotate(t_Stack **stack);
void				swap(t_Stack **stack);
void				pb(t_Stack **a, t_Stack **b);
void				pa(t_Stack **b, t_Stack **a);
void				sa(t_Stack **a);
void				sb(t_Stack **b);
void				ra(t_Stack **a);
void				rb(t_Stack **b);
void				rra(t_Stack **a);
void				rrb(t_Stack **b);
void				rrr(t_Stack **a, t_Stack **b);
void				ft_sortstack(t_Stack **a, t_Stack **b, int *arrya,
						t_chunk *chanks);
int					*ft_sortarrya(t_Stack *a);
int					ft_stack_sortedb(t_Stack *stack);
void				ft_sortthreeb(t_Stack **a, int *array);
void				ft_sortthree(t_Stack **a, int *arrya);
void				rev_rotate1(t_Stack **stack_a, t_Stack **stack_b,
						char *str);
void				rotate1(t_Stack **stack_a, t_Stack **stack_b, char *str);
void				push1(t_Stack **stack_a, t_Stack **stack_b, char *str);
void				swap1(t_Stack **stack_a, t_Stack **stack_b, char *str);
t_Stack				*ft_fill_stack(int ac, char **av);

#endif
