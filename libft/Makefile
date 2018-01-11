# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 12:32:10 by dpolosuk          #+#    #+#              #
#    Updated: 2017/11/10 10:32:45 by dpolosuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(wildcard *.c)
INCLUDE = libft.h
OBJECTS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
	@echo made
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

.c.o:
	@gcc -c $(CFLAGS) -I $(INCLUDE) $(SRC) $<

.PHONY: clean
clean:
	@echo cleaned
	@/bin/rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
	@echo fcleaned
	@/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
