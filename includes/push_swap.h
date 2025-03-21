/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 03:23:26 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/21 12:08:02 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

long	ft_toi(const char *nptr);

void	error_handler(char **argv);

void	ft_stackclear(t_stack *lst);
int		ft_stacksize(t_stack *lst);
int		ft_stackadd_back(t_stack **lst, int value);
t_stack	*ft_pop(t_stack **stack);
int		ft_stackadd_front(t_stack **stack, int value);
void	init_stack(t_stack **stack, int argc, char **argv);
t_stack	*ft_stacklast(t_stack *lst);

int		pb(t_stack **a, t_stack **b);
int		pa(t_stack **a, t_stack **b);
int		ra(t_stack **a);
int		rb(t_stack **b);
int		rr(t_stack **a, t_stack **b);
int		rra(t_stack **a);
int		rrb(t_stack **b);
int		rrr(t_stack **a, t_stack **b);
int		sa(t_stack **a);
int		sb(t_stack **b);
int		ss(t_stack **a, t_stack **b);

void	three_sorting(t_stack **stack);
int		check_sorted_asc(t_stack *stack);
int		check_sorted_desc(t_stack *stack);
int		when_push(t_stack **a, t_stack **b, int dim, int f);
void	quick_sort_3_a_b(t_stack **a, t_stack **b, int dim);
void	tmp_sort(int *tmp_stk, int dim);
int		partition(int *pivot, t_stack *a, int dim);
int		sort_3_b(t_stack **a, t_stack **b, int dim);
int		quick_sort_b(t_stack **a, t_stack **b, int dim, int count_r);
int		quick_sort_a(t_stack **a, t_stack **b, int dim, int count_r);
int		ft_sorter(t_stack **a, t_stack **b);
int		sort(t_stack **a, t_stack **b);

#endif