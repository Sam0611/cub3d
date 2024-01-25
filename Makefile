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
			init_data.c\
			error.c\
			print_screen_game.c\
			game_run.c\
			raycasting.c\
			color.c\
			print_view.c\
			parsing.c\
			create_map.c\
			get_texture.c\
			utils.c\
			check_outline.c\
			read_file.c\
			count.c\
			split_newline.c

SRCS_BONUS	=\
			main_bonus.c\
			init_data_bonus.c\
			error_bonus.c\
			print_screen_game_bonus.c\
			print_minimap_bonus.c\
			game_run_bonus.c\
			raycasting_bonus.c\
			color_bonus.c\
			print_view_bonus.c\
			parsing_bonus.c\
			create_map_bonus.c\
			get_texture_bonus.c\
			utils_bonus.c\
			check_outline_bonus.c\
			read_file_bonus.c\
			count_bonus.c\
			split_newline_bonus.c

OBJS		=	${addprefix ${BUILD_DIR}/,${SRCS:c=o}}
OBJS_BONUS	=	${addprefix ${BUILD_DIR}/,${SRCS_BONUS:c=o}}

NAME		=	${BIN_DIR}/cub3D
NAME_BONUS	=	${BIN_DIR}/cub3D_bonus

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

bonus:	libmlx ${NAME_BONUS}

${NAME_BONUS}:	${OBJS_BONUS}
	@make --no-print-directory ${MODULE} -C libft
	@${CC} ${OBJS_BONUS} ${MLX_FLAGS} ${LIBFT_FLAGS} -o ${NAME_BONUS}

clean:
	@make --no-print-directory fclean -C libft
	@${RM} ${OBJS} ${OBJS_BONUS}

fclean:	clean
	@rm -rf ./MLX42/build
	@${RM} ${NAME} ${NAME_BONUS}

re:	fclean all

.PHONY:	all clean fclean re libmlx bonus

vpath %.c src src/bonus
