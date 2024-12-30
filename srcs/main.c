/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 03:34:35 by sshabali          #+#    #+#             */
/*   Updated: 2024/12/30 05:49:02 by sshabali         ###   ########.fr       */
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
	sort(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}