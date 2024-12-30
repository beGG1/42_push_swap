/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:24:41 by sshabali          #+#    #+#             */
/*   Updated: 2024/12/30 03:39:49 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/ft_printf.h"

int rra(t_stack **a)
{
	int		 len;
	t_stack	*first;
	t_stack	*last;

	len = ft_lstsize(*a);
	if (len <= 1)
		return (1);
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	*a = first->next;
	first->next = 0;
	ft_printf("rra\n");
	return (1);
}

int rrb(t_stack **a)
{
	int		 len;
	t_stack	*first;
	t_stack	*last;

	len = ft_lstsize(*a);
	if (len <= 1)
		return (1);
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	*a = first->next;
	first->next = 0;
	ft_printf("rrb\n");
	return (1);
}

int rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
	return (1);
}