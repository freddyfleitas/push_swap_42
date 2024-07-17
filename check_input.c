/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:25:41 by ffleitas          #+#    #+#             */
/*   Updated: 2024/07/06 16:26:31 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_argv(char **argv)
{
	char	**split;

	split = ft_split(argv[1], ' ');
	if (!split || !*split)
		exit(write(2, "Error\n", 6));
	return (split);
}

char	**check_input(int argc, char **argv)
{
	int	i;
	int	zeros;
	int	is_split;

	i = 1;
	zeros = 0;
	is_split = 0;
	if (argc == 2)
	{
		argv = split_argv(argv);
		i = 0;
		is_split = 1;
	}
	while (argv[i])
	{
		if (!check_syntax(argv[i]) || !check_limits(argv[i]))
			exit_and_free(argv, is_split);
		zeros += check_zeros(argv[i]);
		i ++;
	}
	if (zeros > 1)
		exit_and_free(argv, is_split);
	if (!check_repeated(argc, argv))
		exit_and_free(argv, is_split);
	return (argv);
}
