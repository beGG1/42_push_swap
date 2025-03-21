/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 04:08:52 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/21 11:57:53 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sorting(t_stack **stack)
{
	int	v;
	int	nv;
	int	nnv;

	v = (*stack)->value;
	nv = (*stack)->next->value;
	nnv = (*stack)->next->next->value;
	if ((v < nv) && (v < nnv) && (nv > nnv))
	{
		sa(stack);
		ra(stack);
	}
	else if ((v > nv) && (v > nnv) && (nv > nnv))
	{
		sa(stack);
		rra(stack);
	}
	else if ((v < nv) && (v > nnv) && (nv > nnv))
		rra(stack);
	else if ((v > nv) && (v > nnv) && (nv < nnv))
		ra(stack);
	else if ((v > nv) && (v < nnv) && (nv < nnv))
		sa(stack);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	check_sorted_asc(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_sorted_desc(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	when_push(t_stack **a, t_stack **b, int dim, int f)
{
	if (f == 1)
		pb(a, b);
	else if (f == 0)
		pa(a, b);
	dim--;
	return (dim);
}
