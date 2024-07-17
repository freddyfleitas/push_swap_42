/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:01:40 by ffleitas          #+#    #+#             */
/*   Updated: 2024/07/07 18:55:02 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	highest_unassigned(t_stack *stack, t_stack **highest)
{
	t_stack	*tmp;

	tmp = stack;
	*highest = NULL;
	while (tmp)
	{
		if (!tmp->assigned && (!*highest || tmp->value > (*highest)->value))
			*highest = tmp;
		tmp = tmp->next;
	}
	if (*highest)
		(*highest)->assigned = 1;
}

void	assign_index(t_stack *stack)
{
	t_stack	*highest;
	t_stack	*tmp;
	int		len;

	len = -1;
	tmp = stack;
	while (tmp)
	{
		len ++;
		tmp = tmp->next;
	}
	highest = NULL;
	while (stack && len > 0)
	{
		highest_unassigned(stack, &highest);
		if (highest)
			highest->index = len;
		len --;
	}
}

void	current_pos(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp->actual_pos = i;
		tmp = tmp->next;
		i ++;
	}
}
