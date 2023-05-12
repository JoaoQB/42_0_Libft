# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 13:20:21 by jqueijo-          #+#    #+#              #
#    Updated: 2023/05/08 16:48:56 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#* creates a variable NAME and assigns the value(output) libft.a *#
NAME = libft.a

#* creates a variable SRC and sets it's value to a list of c source files.*#
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

#*defines variable OBJ and set its value to a list of objects from source files.*#
#*syntax $() is a substitution references that replaces .c with .o*#
OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

#*rule that specifies how to build output $(name) from the object files in $(OBJ)
#*begins with name of target $(NAME) then a list of dependencies $(OBJ) that must
#*be built before $(NAME) can be built. The commands to build the target follow
#*the dependencies on the next line, and are indented. The command archives the
#*objects into a static library. r to insert files, c to create archive,
#*s to write index. It's the primary target.
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

#*its a rule specifies that all is a target that depends on $(NAME). Running
#*make all will build $(NAME). Primary target.
all: $(NAME)

#*rule that specifies how to build the bonus part of the library.
bonus: $(B_OBJ)
	ar -rcs $(NAME) $(B_OBJ)
#*force remove.
clean:
	rm -f $(OBJ) $(B_OBJ)

f_clean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re

