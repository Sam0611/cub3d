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

SRC			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
		  		ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c		

BUILD_DIR	=	build
BIN_DIR		= 	bin

OBJ		=	${addprefix ${BUILD_DIR}/,${SRC:.c=.o}}

NAME 		=	${BIN_DIR}/lst.a

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
