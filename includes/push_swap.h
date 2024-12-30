/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 03:23:26 by sshabali          #+#    #+#             */
/*   Updated: 2024/12/30 05:26:32 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	ft_lstclear(t_stack **lst);
int		ft_lstsize(t_stack *lst);
int		ft_lstadd_back(t_stack **lst, int value);
t_stack	*ft_pop(t_stack **lst);

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


#endif