/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:03:18 by ffleitas          #+#    #+#             */
/*   Updated: 2024/07/06 16:31:52 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
	{
		if (argv[i + 1] == '\0')
			return (0);
		i ++;
	}
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i ++;
	}
	return (1);
}

int	check_limits(char *argv)
{
	long	number;

	number = 0;
	number = ft_atol(argv);
	if (number > INT_MAX || number < INT_MIN)
		return (0);
	return (1);
}

int	check_zeros(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i ++;
	while (argv[i] && argv[i] == '0')
		i ++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	check_repeated(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j ++;
		}
		i ++;
	}
	return (1);
}

void	exit_and_free(char **argv, int is_split)
{
	int	i;

	i = 0;
	if (is_split)
	{
		while (argv[i])
		{
			free(argv[i]);
			i ++;
		}
		free(argv);
	}
	exit(write(2, "Error\n", 6));
}
