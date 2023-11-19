# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 14:01:43 by gtroiano          #+#    #+#              #
#    Updated: 2023/11/15 14:14:28 by gtroiano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c \
	   parse.c \

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): 
			$(MAKE) all -C libft
			$(CC) $(CFLAGS) $(SRCS) -L./libft -lft -o $(NAME)

clean:
		$(RM) $(NAME)
		$(MAKE) fclean -C libft

fclean: clean

re: fclean all

.PHONY: all clean fclean re