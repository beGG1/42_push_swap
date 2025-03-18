/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 03:34:35 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/18 17:15:33 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		num;
	
	if (argc == 1)
		return (0);
	error_handler(argv);
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	
	a = NULL;
	
	init_stack(&a, argc, argv);
	sort(&a, &b);
	
	while (a)
	{
		ft_printf("%d ", a->value);
		a = a->next;
	}
	ft_printf("\n");
	return (0);
}