/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:38:47 by sshabali          #+#    #+#             */
/*   Updated: 2025/01/04 10:41:49 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	pb(t_stack **a, t_stack **b)
{
	int		 len;
	t_stack	*first;

	len = ft_stacksize(*a);
	if (len < 1)
		return (0);
	first = ft_pop(a);
	
	if (!ft_stackadd_back(b, first->value))
	{
		ft_stackclear(a);
		ft_stackclear(b);
		free(first);
		return (0);
	}
	free(first);
	ft_printf("pb\n");
	return (1);
}

int	pa(t_stack **a, t_stack **b)
{
	int		 len;
	t_stack	*first;

	len = ft_stacksize(*b);
	if (len < 1)
		return (0);
	first = ft_pop(b);
	
	if (!ft_stackadd_back(a, first->value))
	{
		ft_stackclear(a);
		ft_stackclear(b);
		free(first);
		return (0);
	}
	free(first);
	ft_printf("pa\n");
	return (1);
}