/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:31:54 by ffleitas          #+#    #+#             */
/*   Updated: 2024/07/07 14:38:54 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		len_a;
	int		len_b;

	tmp_b = *stack_b;
	len_a = stack_len(*stack_a);
	len_b = stack_len(*stack_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->actual_pos;
		if (tmp_b->actual_pos > len_b / 2)
			tmp_b->cost_b = (len_b - tmp_b->actual_pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > len_a / 2)
			tmp_b->cost_a = (len_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}
