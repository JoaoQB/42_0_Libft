# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 13:20:21 by jqueijo-          #+#    #+#              #
#    Updated: 2023/05/08 15:55:19 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#* creates a variable NAME and assigns the value(output) libft.a *#
NAME = libft.a

SRC = ft_bzero.c \
		ft_isalpha.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \

B_SRC = \

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

bonus: $(B_OBJ)
	ar -rcs $(NAME) $(B_OBJ)

clean:
	rm -f $(OBJ) $(B_OBJ)

f_clean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re

