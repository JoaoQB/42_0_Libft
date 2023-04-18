# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 09:36:54 by jqueijo-          #+#    #+#              #
#    Updated: 2023/04/18 12:32:31 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strlen.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memset.c \
		ft_bzero.c \
		ft_strlcat.c \

B_SRC = \

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC: .c=.o)

B_OBJ = $(B_SRC: .c=.o)

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
