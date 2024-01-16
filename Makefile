# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smalloir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 13:44:15 by smalloir          #+#    #+#              #
#    Updated: 2023/04/14 21:17:16 by smalloir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=\
			main.c\
			print_screen_game.c\
			print_minimap.c\
			player_infos.c\
			textures.c\
			game_run.c\
			raycasting.c\
			color.c\
			print_view.c\
			parsing.c\
			create_map.c\
			get_texture.c\
			init.c\
			init_data.c\
			utils.c\
			check_outline.c\
			read_file.c\
			error.c

OBJS		=	${addprefix ${BUILD_DIR}/,${SRCS:c=o}}
NAME		=	${BIN_DIR}/cub3D

BUILD_DIR	=	build
BIN_DIR		=	bin

CC			=	clang
RM			=	rm -f
CFLAGS		=	-Wall -Werror -Wextra -Wunreachable-code -g3 -Ilibft/include -Iinclude -IMLX42/include

LIBFT_FLAGS	=	-Llibft/bin -lft
MLX_FLAGS	=	./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

MODULE		=	gnl write stdlib ctype

${BUILD_DIR}/%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@

all:	libmlx ${NAME}

libmlx:
	@cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build -j4

${NAME}:	${OBJS}
	@make --no-print-directory ${MODULE} -C libft
	@${CC} ${OBJS} ${MLX_FLAGS} ${LIBFT_FLAGS} -o ${NAME}

clean:
	@make --no-print-directory fclean -C libft
	@${RM} ${OBJS}

fclean:	clean
	# @rm -rf ./MLX42/build
	@${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re

vpath %.c src
