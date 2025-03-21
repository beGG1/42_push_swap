/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:48:47 by sshabali          #+#    #+#             */
/*   Updated: 2025/03/21 11:34:52 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	duplication_error(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strncmp(argv[i], argv[j], 100))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static void	check_integers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static void	check_convertions(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_toi(argv[i]) > INT_MAX || ft_toi(argv[i]) < INT_MIN)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

static void	check_for_zero(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0' || (argv[i][0] == '0' && ft_strlen(argv[i]) > 1) 
			|| (argv[i][0] == '-' && argv[i][1] == '0'))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	error_handler(char **argv)
{
	duplication_error(argv);
	check_integers(argv);
	check_convertions(argv);
	check_for_zero(argv);
}
