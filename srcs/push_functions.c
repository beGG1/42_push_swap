/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:38:47 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/21 11:38:02 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	pb(t_stack **a, t_stack **b)
{
	t_stack	*first;

	if (!a || !(*a))
		return (0);
	first = ft_pop(a);
	if (!first)
		return (0);
	if (!ft_stackadd_front(b, first->value))
	{
		free(first);
		return (0);
	}
	free(first);
	ft_printf("pb\n");
	return (1);
}

int	pa(t_stack **a, t_stack **b)
{
	t_stack	*first;

	if (!b || !(*b))
		return (0);
	first = ft_pop(b);
	if (!first)
		return (0);
	if (!ft_stackadd_front(a, first->value))
	{
		free(first);
		return (0);
	}
	free(first);
	ft_printf("pa\n");
	return (1);
}
