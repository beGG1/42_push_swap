/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:21:47 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/19 14:33:18 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ra(t_stack **a)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!a || !(*a) || !(*a)->next)
		return (0); // No need to rotate if empty or only one element

	last = *a;
	prev_last = NULL;

	// Traverse to the last node
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}

	// Re-link last node to the first
	last->next = *a;
	*a = (*a)->next; // New head is second element
	last->next->next = NULL; // Previous last node is now last

	ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **a)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!a || !(*a) || !(*a)->next)
		return (0); // No need to rotate if empty or only one element

	last = *a;
	prev_last = NULL;

	// Traverse to the last node
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}

	// Re-link last node to the first
	last->next = *a;
	*a = (*a)->next; // New head is second element
	last->next->next = NULL; // Previous last node is now last

	ft_printf("ra\n");
	return (1);
}

int	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
	return (1);
}