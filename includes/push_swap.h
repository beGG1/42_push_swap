/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 03:23:26 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/20 14:32:39 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	ft_stackclear(t_stack *lst);
int		ft_stacksize(t_stack *lst);
int		ft_stackadd_back(t_stack **lst, int value);
int	ft_stackadd_front(t_stack **stack, int value);
t_stack	*ft_pop(t_stack **lst);
void	init_stack(t_stack **stack, int argc, char **argv);

int	sa(t_stack **a);
int	sb(t_stack **a);
int	ss(t_stack **a, t_stack **b);
int	pa(t_stack **a, t_stack **b);
int	pb(t_stack **a, t_stack **b);
int	ra(t_stack **a);
int	rb(t_stack **a);
int	rr(t_stack **a, t_stack **b);
int	rra(t_stack **a);
int	rrb(t_stack **a);
int	rrr(t_stack **a, t_stack **b);
int sort(t_stack **a, t_stack **b);

long	ft_toi(const char *nptr);

void	error_handler(char **argv);

int	quick_sort_a(t_stack **a, t_stack **b, int dim, int count_r);


#endif