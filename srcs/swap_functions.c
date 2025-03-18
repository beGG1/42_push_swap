/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:11:54 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/18 17:24:43 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!a || !(*a) || !(*a)->next)
		return (1); // No need to swap if empty or one element

	first = *a;
	second = (*a)->next;

	// Swap values instead of removing and re-adding nodes
	int temp = first->value;
	first->value = second->value;
	second->value = temp;

	ft_printf("sa\n");
	return (1);
}

int	sb(t_stack **a)
{
	int		 len;
	t_stack	*first;
	t_stack	*second;

	len = ft_stacksize(*a);
	if (len <= 1)
		return (1);
	first = ft_pop(a);
	second = ft_pop(a);
	
	if (!ft_stackadd_back(a, first->value) || !ft_stackadd_back(a, second->value))
	{
		ft_stackclear(a);
		free(first);
		free(second);
		return (0);
	}
	free(first);
	free(second);
	ft_printf("sb\n");
	return (1);
}

int ss(t_stack **a, t_stack **b)
{
	if (!sa(a) || !sb(b))
	{
		ft_stackclear(a);
		ft_stackclear(b);
		return (0);
	}
	ft_printf("ss\n");
	return (1);
}