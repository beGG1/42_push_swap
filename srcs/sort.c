/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 04:08:52 by sshabali          #+#    #+#             */
/*   Updated: 2024/12/30 05:50:54 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
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

	while (ft_lstsize(*a))
	{
		aa = ft_lstlast(*a)-> value;
		while (ft_lstsize(*b) && ft_lstlast(*b)->value > aa)
		{
			pa(a, b);
			sa(a);
		}
		pb(a, b);
	}
	while (ft_lstsize(*b))
		pa(a, b);
	return (1);
}