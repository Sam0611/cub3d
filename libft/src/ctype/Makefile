# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smalloir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 13:44:15 by smalloir          #+#    #+#              #
#    Updated: 2023/03/16 20:13:07 by smalloir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_isalnum.c	\
		  		ft_isalpha.c	\
		  		ft_isascii.c	\
		  		ft_isdigit.c	\
			 	ft_isprint.c	\
		  		ft_tolower.c	\
		  		ft_toupper.c

BUILD_DIR	=	build
BIN_DIR		= 	bin

OBJ			=	${addprefix ${BUILD_DIR}/,${SRC:c=o}}

NAME 		=	${BIN_DIR}/ctype.a

CC			= clang
CFLAGS		= -Wall -Werror -Wextra -g

RM			= rm -f

${BUILD_DIR}/%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@

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
