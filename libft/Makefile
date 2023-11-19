# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 16:32:43 by gtroiano          #+#    #+#              #
#    Updated: 2023/07/31 11:06:15 by gtroiano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

files	= ft_split \
		  ft_strjoin \
		  ft_strlcat \
		  ft_strlcpy \
		  ft_strlen \
		  ft_strncmp \

Compiler	= gcc

CmpFlags	= -Wall -Wextra -Werror

OUTN	= $(NAME)

CFILES	= $(files:%=%.c)

OFILES	= $(files:%=%.o)

$(NAME):
	$(Compiler) $(CmpFlags) -c $(CFILES) -I./
	ar -rc $(OUTN) $(OFILES)

all: $(NAME)

clean:
	rm -f $(NAME)
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
