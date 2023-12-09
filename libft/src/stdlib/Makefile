# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smalloir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 13:44:15 by smalloir          #+#    #+#              #
#    Updated: 2023/03/16 20:20:35 by smalloir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_atoi.c		\
				ft_calloc.c		\
				ft_itoa.c

BUILD_DIR	=	build
BIN_DIR		= 	bin

OBJ		=	${addprefix ${BUILD_DIR}/,${SRC:.c=.o}}

NAME 		=	${BIN_DIR}/stdlib.a

CC			= clang
CFLAGS		= -Wall -Werror -Wextra -g -I../../include

RM			= rm -f

all:		${NAME}

${NAME}: 	${OBJ}
	@ar -rc ${NAME} ${OBJ}
	@ranlib ${NAME}

${BUILD_DIR}/%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJ}

fclean:	clean
	@${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re

vpath %.c src
