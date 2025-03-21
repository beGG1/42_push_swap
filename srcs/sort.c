/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 04:08:52 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/19 15:31:57 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sorting(t_stack **stack)
{
	if (((*stack)->value < (*stack)->next->value) && ((*stack)->value < (*stack)->next->next->value)
		&& ((*stack)->next->value > (*stack)->next->next->value))
	{
		sa(stack);
		ra(stack);
	}
	else if (((*stack)->value > (*stack)->next->value) && ((*stack)->value > (*stack)->next->next->value)
		&& ((*stack)->next->value > (*stack)->next->next->value))
	{
		sa(stack);
		rra(stack);
	}
	else if (((*stack)->value < (*stack)->next->value) && ((*stack)->value > (*stack)->next->next->value)
		&& ((*stack)->next->value > (*stack)->next->next->value))
		rra(stack);
	else if (((*stack)->value > (*stack)->next->value) && ((*stack)->value > (*stack)->next->next->value)
		&& ((*stack)->next->value < (*stack)->next->next->value))
		ra(stack);
	else if (((*stack)->value > (*stack)->next->value) && ((*stack)->value < (*stack)->next->next->value)
		&& ((*stack)->next->value < (*stack)->next->next->value))
		sa(stack);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	check_sorted_asc(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_sorted_desc(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	when_push(t_stack **a, t_stack **b, int dim, int f)
{
	if (f == 1)
		pb(a, b);
	else if (f == 0)
		pa(a, b);
	dim--;
	return (dim);
}

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
			if (dim == 3 && (*a)->value > (*a)->next->value && (*a)->next->next->value)
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
		while (dim || !((*a)->value < (*a)->next->value && (*a)->next->value < (*a)->next->next->value))
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