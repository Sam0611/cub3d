# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smalloir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 13:44:15 by smalloir          #+#    #+#              #
#    Updated: 2023/03/16 20:18:34 by smalloir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_putchar_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_putstr_fd.c

BUILD_DIR	=	build
BIN_DIR		= 	bin

OBJ		=	${addprefix ${BUILD_DIR}/,${SRC:.c=.o}}

NAME 		=	${BIN_DIR}/write.a

CC			= clang
CFLAGS		= -Wall -Werror -Wextra -g

RM			= rm -f

${BUILD_DIR}/%.o : %.c
	@${CC} -c $< -o $@

all:		${NAME}

${NAME}: 	${OBJ}
	@ar -rc ${NAME} ${OBJ}
	@ranlib ${NAME}

clean:
	@${RM} ${OBJ}

fclean:	clean
	@${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re

vpath %.c src
