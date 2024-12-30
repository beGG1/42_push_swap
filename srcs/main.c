/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 03:34:35 by sshabali          #+#    #+#             */
/*   Updated: 2024/12/30 04:12:16 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/ft_printf.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		num;
	
	a = NULL;
	b= NULL;
	while (argc >= 2)
	{
		if (!ft_atoi(argv[argc - 1], &num))
		{
			ft_lstclear(&a);
			return (1);
		}
		if (!ft_lstadd_back(&a, num))
		{
			ft_lstclear(&a);
			return (1);
		}
		argc--;
	
	}
	int len = ft_lstsize(a);
	t_stack *temp;
	sort(&a, &b);
	while (len)
	{
		temp = ft_pop(&a);
		ft_printf("%d: %d\n", len, temp->value);
		free(temp);
		len--;
	}
	ft_lstclear(&a);
	return (0);
}