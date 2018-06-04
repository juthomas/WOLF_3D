# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/04 18:00:32 by juthomas          #+#    #+#              #
#*   Updated: 2017/05/23 15:15:29 by juthomas         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

.PHONY : all fclean clean re

NAME = wolf3d

SRC = wolf3d_main.c gnl/get_next_line.c wolf3d_loadsprites_1.c \
	  wolf3d_loadsprites_2.c wolf3d_loadsprites_3.c wolf3d_loadsprites_4.c \
	  wolf3d_img_rd_wr.c wolf3d_raycasting_1.c wolf3d_raycasting_2.c \
	  wolf3d_raycasting_3.c wolf3d_map.c wolf3d_parser_1.c \
	  wolf3d_parser_2.c wolf3d_key_analyst_1.c wolf3d_key_analyst_2.c \
	  wolf3d_key_analyst_3.c wolf3d_key_analyst_4.c wolf3d_key_analyst_5.c \
	  wolf3d_utils.c wolf3d_malloc_1.c wolf3d_malloc_2.c

LIB = gnl/libft/libft.a

MLX = -lmlx -framework OpenGL -framework Appkit
CFLAGS = -Ofast -Wall -Werror -Wextra 

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):	$(OBJ)
	make -C gnl/libft/
	make -C gen_map/
	gcc -c $(SRC) mac_keycode/keycode.c
	gcc $(OBJ) keycode.o $(FLAGS) $(LIB) $(MLX) -o $(NAME)

clean :
	make -C gnl/libft/ fclean
	make -C gen_map/ clean
	rm -f $(OBJ)
	rm -f keycode.o

fclean : clean
	make -C gen_map/ fclean
	rm -f $(NAME)

re : fclean all
