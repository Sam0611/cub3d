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

SRCS		=	main.c print_map.c game_run.c player_infos.c raycasting.c color.c print_view.c init_data.c print_minimap.c textures.c
SRCS_BONUS	=	main_bonus.c
OBJS		=	${addprefix ${BUILD_DIR}/,${SRCS:c=o}}
OBJS_BONUS	=	${addprefix ${BUILD_DIR}/,${SRCS_BONUS:c=o}}
NAME		=	${BIN_DIR}/cub3D

BUILD_DIR	=	build
BIN_DIR		=	bin

CC			=	clang
RM			=	rm -f
CFLAGS		=	-Wall -Werror -Wextra -Wunreachable-code -g3 -Ilibft/include -Iinclude -IMLX42/include

LIBFT_FLAGS	=	-Llibft/bin -lft
MLX_FLAGS	=	./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

MODULE			=	printf gnl
MODULE_BONUS	=	printf gnl stdlib

${BUILD_DIR}/%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@

all:	libmlx ${NAME}

libmlx:
	@cmake ./MLX42 -B ./MLX42/build && make -C ./MLX42/build -j4

${NAME}:	${OBJS}
	@make -j --no-print-directory ${MODULE} -C libft
	@${CC} ${OBJS} ${MLX_FLAGS} ${LIBFT_FLAGS} -o ${NAME}

bonus:	${OBJS_BONUS}
	@make -j --no-print-directory ${MODULE_BONUS} -C libft
	@${CC} ${OBJS_BONUS} ${MLX_FLAGS} ${LIBFT_FLAGS} -o ${NAME}

clean:
	@make --no-print-directory fclean -C libft
	# @rm -rf ./MLX42/build
	@${RM} ${OBJS} ${OBJS_BONUS}

fclean:	clean
	@${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re bonus

vpath %.c src
