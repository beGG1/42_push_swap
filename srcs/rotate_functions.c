/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:21:47 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/21 11:43:41 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ra(t_stack **a)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!a || !(*a) || !(*a)->next)
		return (0);
	last = *a;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	last->next = *a;
	*a = (*a)->next;
	last->next->next = NULL;
	ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **b)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!b || !(*b) || !(*b)->next)
		return (0);
	last = *b;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	last->next = *b;
	*b = (*b)->next;
	last->next->next = NULL;
	ft_printf("rb\n");
	return (1);
}

int	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
	return (1);
}
