/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:24:41 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/19 14:33:35 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int rra(t_stack **a)
{
	t_stack *prev_last;
	t_stack *last;

	if (!a || !(*a) || !(*a)->next)
		return (1); // No need to rotate if empty or only one element

	prev_last = NULL;
	last = *a;

	// Find the second-to-last and last node
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}

	// Make the second-to-last node the new last node
	if (prev_last)
		prev_last->next = NULL;

	// Move the last node to the front
	last->next = *a;
	*a = last;

	ft_printf("rra\n");
	return (1);
}


int rrb(t_stack **a)
{
	t_stack *prev_last;
	t_stack *last;

	if (!a || !(*a) || !(*a)->next)
		return (1); // No need to rotate if empty or only one element

	prev_last = NULL;
	last = *a;

	// Find the second-to-last and last node
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}

	// Make the second-to-last node the new last node
	if (prev_last)
		prev_last->next = NULL;

	// Move the last node to the front
	last->next = *a;
	*a = last;

	ft_printf("rra\n");
	return (1);
}

int rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
	return (1);
}