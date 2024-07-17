/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:58:04 by ffleitas          #+#    #+#             */
/*   Updated: 2024/07/07 18:56:45 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	len;
	int	pushed;

	len = stack_len(*stack_a);
	i = 0;
	pushed = 0;
	while (len > 3 && i < len && pushed < len / 2)
	{
		if ((*stack_a)->index <= len / 2)
		{
			pb(stack_a, stack_b, 1);
			pushed++;
		}
		else
			ra(stack_a, 1);
		i++;
	}
	while (stack_len(*stack_a) > 3)
		pb(stack_a, stack_b, 1);
}

static int	find_lowest_index_pos(t_stack *stack_a)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stack_a;
	while (temp && temp->index != 0)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

static void	finish_sort(t_stack **stack_a)
{
	int	len;
	int	pos;

	len = stack_len(*stack_a);
	pos = find_lowest_index_pos(*stack_a);
	if (pos > len / 2)
	{
		while (pos < len)
		{
			rra(stack_a, 1);
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			ra(stack_a, 1);
			pos--;
		}
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	send_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		finish_sort(stack_a);
}
