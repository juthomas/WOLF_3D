# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/04 18:00:32 by juthomas          #+#    #+#              #
#    Updated: 2017/10/17 01:37:55 by juthomas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all fclean clean re

NAME = map_gen

SRC = main_map.c

LIB = ../gnl/libft/libft.a

CFLAGS = -O2 -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
