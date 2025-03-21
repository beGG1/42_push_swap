/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_stack_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:16:59 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/21 11:36:16 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stackclear(t_stack *lst)
{
	t_stack	*temp;

	if (lst)
	{
		while (lst)
		{
			temp = lst->next;
			free(lst);
			lst = temp;
		}
		lst = NULL;
	}
}

int	ft_stacksize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int	ft_stackadd_back(t_stack **lst, int value)
{
	t_stack	*l;
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new) * 1);
	if (new == NULL)
	{
		ft_stackclear(*lst);
		return (1);
	}
	new->value = value;
	new->next = 0;
	if (!lst || !(*lst))
	{
		*lst = new;
		return (1);
	}
	l = *lst;
	while (l->next)
		l = l->next;
	l->next = new;
	return (1);
}

t_stack	*ft_pop(t_stack **stack)
{
	t_stack	*top;

	if (!stack || !*stack)
		return (NULL);
	top = *stack;
	*stack = (*stack)->next;
	top->next = NULL;
	return (top);
}

int	ft_stackadd_front(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
	return (1);
}
