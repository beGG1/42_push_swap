/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:24:41 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/21 11:41:22 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rra(t_stack **a)
{
	t_stack	*prev_last;
	t_stack	*last;

	if (!a || !(*a) || !(*a)->next)
		return (1);
	prev_last = NULL;
	last = *a;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	if (prev_last)
		prev_last->next = NULL;
	last->next = *a;
	*a = last;
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack **b)
{
	t_stack	*prev_last;
	t_stack	*last;

	if (!b || !(*b) || !(*b)->next)
		return (1);
	prev_last = NULL;
	last = *b;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	if (prev_last)
		prev_last->next = NULL;
	last->next = *b;
	*b = last;
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
	return (1);
}
