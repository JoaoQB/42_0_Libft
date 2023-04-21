# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 09:36:54 by jqueijo-          #+#    #+#              #
#    Updated: 2023/04/21 18:20:14 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strlen.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memset.c \
		ft_bzero.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_itoa.c \
		ft_putchar_fd.c \

B_SRC = \

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

$(NAME): $(OBJ)
		ar -rcs $@ $(OBJ)

all: $(NAME)

bonus: $(B_OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ) $(B_OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re
