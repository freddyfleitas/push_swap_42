# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 17:53:49 by ffleitas          #+#    #+#              #
#    Updated: 2024/07/07 19:31:42 by ffleitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libftprintf.a

SRC = push.c reverse_rotate.c rotate.c swap.c assign_index.c big_sort.c \
			check_input.c create_stack.c do_cheapest_move.c do_move.c \
			error_handler.c get_cost.c get_target.c main.c sort_stacks_utils.c \
			sort_stacks.c movements_utils.c

OBJS = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -g3

all: $(NAME)

$(LIBFT):
	@$(MAKE) -s -C libft
	
$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(LIBFT) -o $@
	
clean: 
	@$(MAKE) -s -C libft clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -s -C libft fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re