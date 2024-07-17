/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:51:50 by ffleitas          #+#    #+#             */
/*   Updated: 2024/07/06 19:52:59 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}

static void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack)
	{
		while (*stack)
		{
			tmp = *stack;
			*stack = (*stack)->next;
			free(tmp);
		}
		stack = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	argv = check_input (argc, argv);
	stack_a = create_stack (&stack_a, argc, argv);
	assign_index (stack_a);
	sort_stacks (&stack_a, &stack_b);
	free_argv (argc, argv);
	free_stack (&stack_a);
	free_stack (&stack_b);
	return (0);
}
