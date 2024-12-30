/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:11:54 by sshabali          #+#    #+#             */
/*   Updated: 2024/12/30 05:26:36 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/ft_printf.h"

int	sa(t_stack **a)
{
	int		 len;
	t_stack	*first;
	t_stack	*second;

	len = ft_lstsize(*a);
	if (len <= 1)
		return (1);
	first = ft_pop(a);
	second = ft_pop(a);
	
	if (!ft_lstadd_back(a, first->value) || !ft_lstadd_back(a, second->value))
	{
		ft_lstclear(a);
		free(first);
		free(second);
		return (0);
	}
	free(first);
	free(second);
	ft_printf("sa\n");
	return (1);
}

int	sb(t_stack **a)
{
	int		 len;
	t_stack	*first;
	t_stack	*second;

	len = ft_lstsize(*a);
	if (len <= 1)
		return (1);
	first = ft_pop(a);
	second = ft_pop(a);
	
	if (!ft_lstadd_back(a, first->value) || !ft_lstadd_back(a, second->value))
	{
		ft_lstclear(a);
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
		ft_lstclear(a);
		ft_lstclear(b);
		return (0);
	}
	ft_printf("ss\n");
	return (1);
}