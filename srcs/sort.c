/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 04:08:52 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/18 18:17:42 by sshabali         ###   ########.fr       */
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

int	sort(t_stack **a, t_stack **b)
{
	three_sorting(a);
	return (1);
}