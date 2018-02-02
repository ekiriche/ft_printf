# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/29 13:06:57 by ekiriche          #+#    #+#              #
#    Updated: 2018/02/02 17:54:14 by ekiriche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_LIB = ft_42.c \
		ft_atoi.c \
		ft_bubsort_intarr.c \
		ft_bzero.c \
		ft_dectohex.c \
		ft_dectohexsmall.c \
		ft_dectooct.c \
		ft_is_pow_of_2.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstrev.c \
		ft_lullaby.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_merge.c \
		ft_mergesort_intarr.c \
		ft_nbrlen.c \
		ft_power.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_sqrt.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_swap.c \
		ft_swap_i.c \
		ft_swap_s.c \
		ft_tolower.c \
		ft_toupper.c \
		putunbr.c \
		ft_strnclr.c \

SRC = deal_with_d.c \
		errors.c \
		ft_printf.c \
		handler.c \
		trashcan.c \
		costili.c \
		deal_with_di_start.c \
		deal_with_oct_start.c \
		deal_with_c_start.c \
		deal_with_s_start.c \

OBJ_PATH = ./libft/
INCLUDE = -I ./ft_printf.h -I ./libft/libft.h
OBJ = $(SRC:.c=.o)
OBJ_LIB = $(addprefix $(OBJ_PATH), $(SRC_LIB:.c=.o))
CFLAGS = -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIB)
	@ar rc $(NAME) $(OBJ) $(OBJ_LIB)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@rm -f $(OBJ) $(OBJ_LIB)

fclean: clean
	@rm -f $(NAME)

re: fclean all
