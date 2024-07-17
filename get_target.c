/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:53:55 by ffleitas          #+#    #+#             */
/*   Updated: 2024/07/07 17:09:09 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_closest_target(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->actual_pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->actual_pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	get_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		target;

	tmp_b = *stack_b;
	target = 0;
	current_pos(*stack_a);
	current_pos(*stack_b);
	while (tmp_b)
	{
		target = find_closest_target(stack_a, tmp_b->index, INT_MAX, target);
		tmp_b->target_pos = target;
		tmp_b = tmp_b->next;
	}
}
