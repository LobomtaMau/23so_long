# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 11:05:06 by mbaptist          #+#    #+#              #
#    Updated: 2023/10/12 13:26:33 by mbaptist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = 	check_args.c \
		load_textures.c \
		moves.c \
		read_check_map.c \
		so_long.c \
		start_game.c \
		util1.c \
		util2.c \
		util3.c \
		util4.c \

SRC_DIR = src
OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -fr

all: $(NAME)

$(NAME): $(OBJ)
	cd mlx_linux && ./configure
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib \
	-Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
		$(RM) $(OBJ_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re