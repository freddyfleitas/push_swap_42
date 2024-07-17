/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:44:17 by ffleitas          #+#    #+#             */
/*   Updated: 2024/07/07 19:03:12 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct stack
{
	int				value;
	int				index;
	int				actual_pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				assigned;
	struct stack	*next;
	struct stack	*prev;
}		t_stack;

/*Swap*/
void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);
/*Push*/
void	pa(t_stack **stack_a, t_stack **stack_b, int print);
void	pb(t_stack **stack_a, t_stack **stack_b, int print);
/*Rotate*/
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);
/*Reverse Rotate*/
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);

/*Assign_index.c*/
void	assign_index(t_stack *stack);
void	current_pos(t_stack *stack);

/*Big_sort.c*/
void	big_sort(t_stack **stack_a, t_stack **stack_b);

/*Check_input.c*/
char	**check_input(int argc, char **argv);
char	**split_argv(char **argv);

/*Create_stack.c*/
t_stack	*create_stack(t_stack **stack, int argc, char **argv);

/*Do_cheapest_move.c*/
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/*Do_move.c*/
void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

/*Eror_handler.c*/
int		check_syntax(char *argv);
int		check_limits(char *argv);
int		check_zeros(char *argv);
int		check_repeated(int argc, char **argv);
void	exit_and_free(char **argv, int is_split);

/*Get_cost.c*/
void	get_cost(t_stack **stack_a, t_stack **stack_b);

/*Get_target.c*/
void	get_target(t_stack **stack_a, t_stack **stack_b);

/*Sort_stacks.c*/
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);

/*Sort_stacks_utils.c*/
int		is_sorted(t_stack **stack_a);
int		stack_len(t_stack *stack);

#endif
