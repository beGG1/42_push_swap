/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_stack_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:16:59 by sshabali          #+#    #+#             */
/*   Updated: 2025/01/04 10:36:42 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stackclear(t_stack **lst)
{
	if (!lst || !(*lst))
		return ;
	ft_stackclear(&(*lst)->next);
	free(*lst);
	*lst = 0;
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
		ft_stackclear(lst);
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

t_stack	*ft_pop(t_stack **lst)
{
	t_stack	*l;
	t_stack	*temp;
	int		size;

	if (!lst || !(*lst))
		return (NULL);
	l = *lst;
	size = ft_stacksize(l);
	if (size == 1)
	{
		temp = l;
		*lst = NULL;
		return (temp);
	}
	while (size - 2 > 0)
	{
		l = l->next;
		size--;
	}
	temp = l->next;
	l->next = NULL;
	return (temp);
}
