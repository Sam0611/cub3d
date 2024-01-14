# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smalloir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 13:44:15 by smalloir          #+#    #+#              #
#    Updated: 2023/04/13 23:02:29 by smalloir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_bzero.c			\
		  		ft_countchar.c		\
		  		ft_findchar.c		\
		  		ft_findstr.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_memset.c			\
				ft_replace_char.c	\
				ft_split.c			\
				ft_strchr.c			\
				ft_strcpy.c			\
				ft_strdup.c			\
				ft_striteri.c		\
				ft_strjoin.c		\
				ft_strlcat.c		\
				ft_strlcpy.c		\
				ft_strlen.c			\
				ft_strmapi.c		\
				ft_strncmp.c		\
				ft_strnstr.c		\
				ft_strrchr.c		\
				ft_strsearch.c		\
				ft_strsearch_chars.c\
				ft_strnsearch.c		\
				ft_strtrim.c		\
				ft_substr.c			\

BUILD_DIR	=	build
BIN_DIR		= 	bin

OBJ		=	${addprefix ${BUILD_DIR}/,${SRC:.c=.o}}

NAME 		=	${BIN_DIR}/string.a

CC			= clang
CFLAGS		= -Wall -Werror -Wextra -g -I../../include

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
