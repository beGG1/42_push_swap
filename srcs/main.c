/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 03:34:35 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/21 11:36:50 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

void	init_stack(t_stack **stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc) 
	{
		ft_stackadd_back(stack, (int)ft_toi(argv[i]));
		i++;
	}
}

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
	b = NULL;
	init_stack(&a, argc, argv);
	sort(&a, &b);
	ft_stackclear(a);
	ft_stackclear(b);
	return (0);
}
