/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:21:47 by sshabali          #+#    #+#             */
/*   Updated: 2024/12/30 03:50:52 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/ft_printf.h"

int	ra(t_stack **a)
{
	int		 len;
	t_stack	*last;
	t_stack	*prev_last;

	len = ft_lstsize(*a);
	if (len <= 1)
		return (1);
	last = *a;
	prev_last = *a;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	last->next = *a;
	*a = prev_last->next;
	prev_last->next = 0;
	ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **a)
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
	a = &first->next;
	first->next = 0;
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