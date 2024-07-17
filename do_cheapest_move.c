/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cheapest_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:24:57 by ffleitas          #+#    #+#             */
/*   Updated: 2024/07/07 18:53:17 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp_b = *stack_b;
	cheapest = INT_MAX;
	while (tmp_b)
	{
		if (ft_abs(tmp_b->cost_a) + ft_abs(tmp_b->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(tmp_b->cost_a) + ft_abs(tmp_b->cost_b);
			cost_a = tmp_b->cost_a;
			cost_b = tmp_b->cost_b;
		}
		tmp_b = tmp_b->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
