/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:55:15 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/21 11:58:46 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	quick_sort_3_a_b(t_stack **a, t_stack **b, int dim)
{
	if (dim == 3 && ft_stacksize(*a) == 3)
		three_sorting(a);
	else if (dim == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (dim == 3)
	{
		while (dim != 3 || !((*a)->value < (*a)->next->value
				&& (*a)->next->value < (*a)->next->next->value))
		{
			if (dim == 3 && (*a)->value > (*a)->next->value 
				&& (*a)->next->next->value)
				sa(a);
			else if (dim == 3 && !((*a)->next->next->value > (*a)->value
					&& (*a)->next->next->value > (*a)->next->value))
				dim = when_push(a, b, dim, 1);
			else if ((*a)->value > (*a)->next->value)
				sa(a);
			else if (dim++)
				pa(a, b);
		}
	}
}

void	tmp_sort(int *tmp_stk, int dim)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < dim)
	{
		j = i + 1;
		while (j < dim)
		{
			if (tmp_stk[i] > tmp_stk[j])
			{
				tmp = tmp_stk[i];
				tmp_stk[i] = tmp_stk[j];
				tmp_stk[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	partition(int *pivot, t_stack *a, int dim)
{
	int	*tmp;
	int	j;

	tmp = (int *)malloc(sizeof(int) * dim);
	if (!tmp)
		return (0);
	j = 0;
	while (j < dim)
	{
		tmp[j++] = a->value;
		a = a->next;
	}
	tmp_sort(tmp, dim);
	*pivot = tmp[dim / 2];
	free(tmp);
	return (1);
}

int	sort_3_b(t_stack **a, t_stack **b, int dim)
{
	if (dim == 1)
		pa(a, b);
	else if (dim == 2)
	{
		if ((*b)->value < (*b)->next->value)
			sb(b);
		while (dim--)
			pa(a, b);
	}
	else if (dim == 3)
	{
		while (dim || !((*a)->value < (*a)->next->value 
				&& (*a)->next->value < (*a)->next->next->value))
		{
			if (dim == 1 && (*a)->value > (*a)->next->value)
				sa(a);
			else if (dim == 1
				|| (dim >= 2 && (*b)->value > (*b)->next->value)
				|| (dim == 3 && (*b)->value > (*b)->next->next->value))
				dim = when_push(a, b, dim, 0);
			else
				sb(b);
		}
	}
	return (0);
}

int	quick_sort_b(t_stack **a, t_stack **b, int dim, int count_r)
{
	int	pivot;
	int	numbers;

	if (!count_r && check_sorted_desc(*b) == 1)
		while (dim--)
			pa(a, b);
	if (dim <= 3)
	{
		sort_3_b(a, b, dim);
		return (1);
	}
	numbers = dim;
	if (!partition(&pivot, *b, dim))
		return (0);
	while (dim != numbers / 2)
	{
		if ((*b)->value >= pivot && dim--)
			pa(a, b);
		else if (++count_r)
			rb(b);
	}
	while (numbers / 2 != ft_stacksize(*b) && count_r--)
		rrb(b);
	return (quick_sort_a(a, b, numbers / 2 + numbers % 2, 0)
		&& quick_sort_b(a, b, numbers / 2, 0));
}
