/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:56:31 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/21 11:57:12 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	quick_sort_a(t_stack **a, t_stack **b, int dim, int count_r)
{
	int	pivot;
	int	numbers;

	if (check_sorted_asc(*a) == 1)
		return (1);
	numbers = dim;
	if (dim <= 3)
	{
		quick_sort_3_a_b(a, b, dim);
		return (1);
	}
	if (!count_r && !partition(&pivot, *a, dim))
		return (0);
	while (dim != numbers / 2 + numbers % 2)
	{
		if ((*a)->value < pivot && (dim--))
			pb(a, b);
		else if (++count_r)
			ra(a);
	}
	while (count_r--)
		rra(a);
	return (quick_sort_a(a, b, numbers / 2 + numbers % 2, 0)
		&& quick_sort_b(a, b, numbers / 2, 0));
	return (1);
}

int	ft_sorter(t_stack **a, t_stack **b)
{
	if (!check_sorted_asc(*a))
	{
		if (ft_stacksize(*a) == 2)
			sa(a);
		else if (ft_stacksize(*a) == 3)
			three_sorting(a);
		else
			quick_sort_a(a, b, ft_stacksize(*a), 0);
	}
	return (0);
}

int	sort(t_stack **a, t_stack **b)
{
	return (ft_sorter(a, b));
}
