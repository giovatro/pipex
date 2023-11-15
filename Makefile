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

SRCS = pipex.c \
	   parse.c \

LIBFT = libft/libft.a

OBJS = $(SRCS:.C=.O)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT)
	$(MAKE) -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
