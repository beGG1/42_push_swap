/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 04:08:52 by sshabali          #+#    #+#             */
/*   Updated: 2025/01/04 10:40:48 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	sort(t_stack **a, t_stack **b)
{
	int aa;

	while (ft_stacksize(*a))
	{
		aa = ft_stacklast(*a)-> value;
		while (ft_stacksize(*b) && ft_stacklast(*b)->value > aa)
		{
			pa(a, b);
			sa(a);
		}
		pb(a, b);
	}
	while (ft_stacksize(*b))
		pa(a, b);
	return (1);
}