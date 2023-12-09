# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smalloir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 13:44:15 by smalloir          #+#    #+#              #
#    Updated: 2023/03/14 18:27:05 by smalloir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_printf.c ft_putcharstrnb.c ft_strnblen.c ft_putnbr_base.c mdt.c
SRC_BONUS	=	bonus1.c bonus2.c b1dz.c b1size.c b1flags.c b1_wp_sp.c

BUILD_DIR	=	build
BIN_DIR		= 	bin

OBJ			=	${addprefix ${BUILD_DIR}/,${SRC:.c=.o}}
OBJ_BONUS	=	${addprefix ${BUILD_DIR}/,${SRC_BONUS:.c=.o}}

NAME 		=	${BIN_DIR}/printf.a

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra -g -I../../include

RM			=	rm -f

all:		${NAME}

${NAME}: 	${OBJ} bonus
	@ar -rc ${NAME} ${OBJ} ${OBJ_BONUS}
	@ranlib ${NAME}

${BUILD_DIR}/%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@

bonus:
	@${CC} ${CFLAGS} -c src/bonus/bonus1.c -o ${BUILD_DIR}/bonus1.o
	@${CC} ${CFLAGS} -c src/bonus/bonus2.c -o ${BUILD_DIR}/bonus2.o
	@${CC} ${CFLAGS} -c src/bonus/b1dz.c -o ${BUILD_DIR}/b1dz.o
	@${CC} ${CFLAGS} -c src/bonus/b1size.c -o ${BUILD_DIR}/b1size.o
	@${CC} ${CFLAGS} -c src/bonus/b1flags.c -o ${BUILD_DIR}/b1flags.o
	@${CC} ${CFLAGS} -c src/bonus/b1_wp_sp.c -o ${BUILD_DIR}/b1_wp_sp.o

clean:
	@${RM} ${OBJ} ${OBJ_BONUS}

fclean:	clean
	@${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re

vpath %.c src
