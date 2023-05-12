# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 09:36:54 by jqueijo-          #+#    #+#              #
#    Updated: 2023/05/12 14:24:36 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

IS = is/
LST = lst/
MEM = mem/
PUT = put/
STR = str/
TO = to/
PF = pf/


SRC = $(TO)ft_atoi.c \
	$(IS)ft_isalnum.c \
	$(IS)ft_isalpha.c \
	$(IS)ft_isascii.c \
	$(IS)ft_isdigit.c \
	$(IS)ft_isprint.c \
	$(IS)ft_isdigit.c \
	$(IS)ft_isprint.c \
	$(TO)ft_toupper.c \
	$(TO)ft_tolower.c \
	$(MEM)ft_memset.c \
	$(MEM)ft_bzero.c \
	$(MEM)ft_memcpy.c \
	$(MEM)ft_memcmp.c \
	$(MEM)ft_memmove.c \
	$(MEM)ft_memchr.c \
	$(STR)ft_strlcpy.c \
	$(STR)ft_strlcat.c \
	$(STR)ft_strlen.c \
	$(STR)ft_strchr.c \
	$(STR)ft_strrchr.c \
	$(STR)ft_strncmp.c \
	$(STR)ft_strnstr.c \
	$(STR)ft_strdup.c \
	$(STR)ft_substr.c \
	$(STR)ft_strjoin.c \
	$(STR)ft_strtrim.c \
	$(MEM)ft_calloc.c \
	$(STR)ft_split.c \
	$(TO)ft_itoa.c \
	$(STR)ft_strmapi.c \
	$(STR)ft_striteri.c \
	$(PUT)ft_putchar_fd.c \
	$(PUT)ft_putstr_fd.c \
	$(PUT)ft_putendl_fd.c \
	$(PUT)ft_putnbr_fd.c \

B_SRC = $(LST)ft_lstnew.c \
	$(LST)ft_lstadd_front.c \
	$(LST)ft_lstsize.c \
	$(LST)ft_lstlast.c \
	$(LST)ft_lstadd_back.c \
	$(LST)ft_lstdelone.c \
	$(LST)ft_lstclear.c \
	$(LST)ft_lstiter.c \
	$(LST)ft_lstmap.c \

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $@ $(OBJ)

all: $(NAME)

bonus: $(B_OBJ)
	ar -rcs $(NAME) $(B_OBJ)

clean:
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re
