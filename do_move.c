/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:03:09 by ffleitas          #+#    #+#             */
/*   Updated: 2024/07/07 18:39:05 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rrr(t_stack **stack_a, t_stack **stack_b, int *cost_a,
	int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b, 1);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	do_rr(t_stack **stack_a, t_stack **stack_b, int *cost_a,
	int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b, 1);
		(*cost_a)--;
		(*cost_b)--;
	}
}

static void	do_ra(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(stack_a, 1);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(stack_a, 1);
			(*cost)++;
		}
	}
}

static void	do_rb(t_stack **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(stack_b, 1);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(stack_b, 1);
			(*cost)++;
		}
	}
}

void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rrr(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rr(stack_a, stack_b, &cost_a, &cost_b);
	do_ra(stack_a, &cost_a);
	do_rb(stack_b, &cost_b);
	pa(stack_a, stack_b, 1);
}
