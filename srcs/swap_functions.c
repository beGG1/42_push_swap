/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:11:54 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/21 11:54:13 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	if (!a || !(*a) || !(*a)->next)
		return (0);
	first = *a;
	second = (*a)->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	ft_printf("sa\n");
	return (1);
}

int	sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	if (!b || !(*b) || !(*b)->next)
		return (0);
	first = *b;
	second = (*b)->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	ft_printf("sb\n");
	return (1);
}

int	ss(t_stack **a, t_stack **b)
{
	if (!sa(a) || !sb(b))
	{
		ft_stackclear(*a);
		ft_stackclear(*b);
		return (0);
	}
	ft_printf("ss\n");
	return (1);
}
