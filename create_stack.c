/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:07:26 by ffleitas          #+#    #+#             */
/*   Updated: 2024/07/07 19:29:16 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_stack	*init_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->actual_pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

static void	fill_stack(t_stack **stack, char **argv)
{
	t_stack	*new;
	t_stack	*last;

	new = init_new(ft_atoi(*argv));
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}

t_stack	*create_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*a;

	a = *stack;
	if (argc >= 3)
		argv++;
	while (*argv)
	{
		fill_stack (&a, argv);
		argv++;
	}
	return (a);
}
