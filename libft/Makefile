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

BIN_DIR		= 	bin

NAME 		=	${BIN_DIR}/libft.a

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra -g

MAKE		=	make --no-print-directory -C src
FCLEAN		=	make --no-print-directory fclean -C src
RM			=	rm -f

all:		${NAME}

${NAME}:	ctype gnl lst printf stdlib string write
	@ranlib ${NAME}

ctype:
	@${MAKE}/ctype
	@ar -rc ${NAME} src/ctype/build/*.o

gnl:	string
	@${MAKE}/gnl
	@ar -rc ${NAME} src/gnl/build/*.o

lst:
	@${MAKE}/lst
	@ar -rc ${NAME} src/lst/build/*.o

printf:	stdlib string
	@${MAKE}/printf
	@ar -rc ${NAME} src/printf/build/*.o

stdlib:
	@${MAKE}/stdlib
	@ar -rc ${NAME} src/stdlib/build/*.o

string:
	@${MAKE}/string
	@ar -rc ${NAME} src/string/build/*.o

write:
	@${MAKE}/write
	@ar -rc ${NAME} src/write/build/*.o

clean:
	@${FCLEAN}/ctype
	@${FCLEAN}/gnl
	@${FCLEAN}/lst
	@${FCLEAN}/printf
	@${FCLEAN}/stdlib
	@${FCLEAN}/string
	@${FCLEAN}/write

fclean:	clean
	@${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
