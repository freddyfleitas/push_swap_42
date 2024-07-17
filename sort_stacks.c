/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:03:37 by ffleitas          #+#    #+#             */
/*   Updated: 2024/07/06 16:54:28 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->index > (*stack_a)->next->next->index)
		ra(stack_a, 1);
	else if ((*stack_a)->next->index > (*stack_a)->index
		&& (*stack_a)->next->index > (*stack_a)->next->next->index)
		rra(stack_a, 1);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, 1);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (!is_sorted(stack_a))
	{
		if (len == 2)
			sa(stack_a, 1);
		else if (len == 3)
			sort_three(stack_a);
		else
			big_sort(stack_a, stack_b);
	}
}
