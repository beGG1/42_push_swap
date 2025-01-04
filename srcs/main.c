/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 03:34:35 by sshabali          #+#    #+#             */
/*   Updated: 2025/01/04 10:43:38 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		num;
	
	a = NULL;
	b= NULL;
	while (argc >= 2)
	{
		if (0)
		{
			ft_stackclear(&a);
			return (1);
		}
		if (!ft_stackadd_back(&a, num))
		{
			ft_stackclear(&a);
			return (1);
		}
		argc--;
	
	}
	sort(&a, &b);
	ft_stackclear(&a);
	ft_stackclear(&b);
	return (0);
}