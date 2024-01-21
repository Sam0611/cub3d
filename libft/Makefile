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

CTYPE_DIR	=	src/ctype/build
SRCS_CTYPE	=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c
OBJS_CTYPE	=	${addprefix ${CTYPE_DIR}/,${SRCS_CTYPE:c=o}}

GNL_DIR		=	src/gnl/build
SRCS_GNL	=	get_next_line.c get_next_line_bonus.c get_all_lines.c
OBJS_GNL	=	${addprefix ${GNL_DIR}/,${SRCS_GNL:c=o}}

LST_DIR		=	src/lst/build
SRCS_LST	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
		  		ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS_LST	=	${addprefix ${LST_DIR}/,${SRCS_LST:c=o}}

PRINTF_DIR	=	src/printf/build
SRCS_PRINTF	=	ft_printf.c ft_putcharstrnb.c ft_strnblen.c ft_putnbr_base.c mdt.c \
				bonus1.c bonus2.c b1dz.c b1size.c b1flags.c b1_wp_sp.c
OBJS_PRINTF	=	${addprefix ${PRINTF_DIR}/,${SRCS_PRINTF:c=o}}

STDLIB_DIR	=	src/stdlib/build
SRCS_STDLIB	=	ft_atoi.c ft_calloc.c ft_itoa.c
OBJS_STDLIB	=	${addprefix ${STDLIB_DIR}/,${SRCS_STDLIB:c=o}}

STRING_DIR	=	src/string/build
SRCS_STRING	=	ft_bzero.c ft_countchar.c ft_findchar.c ft_findstr.c	\
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c	\
				ft_replace_char.c ft_split.c ft_strchr.c ft_strcpy.c ft_strdup.c	\
				ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c	\
				ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c		\
				ft_strsearch.c ft_strsearch_chars.c ft_strnsearch.c		\
				ft_strtrim.c ft_substr.c
OBJS_STRING	=	${addprefix ${STRING_DIR}/,${SRCS_STRING:c=o}}

WRITE_DIR	=	src/write/build
SRCS_WRITE	=	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
OBJS_WRITE	=	${addprefix ${WRITE_DIR}/,${SRCS_WRITE:c=o}}


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
	@ar -rc ${NAME} ${OBJS_CTYPE}

gnl:	string
	@${MAKE}/gnl
	@ar -rc ${NAME} ${OBJS_GNL}

lst:
	@${MAKE}/lst
	@ar -rc ${NAME} ${OBJS_LST}

printf:	stdlib string
	@${MAKE}/printf
	@ar -rc ${NAME} ${OBJS_PRINTF}

stdlib:
	@${MAKE}/stdlib
	@ar -rc ${NAME} ${OBJS_STDLIB}

string:
	@${MAKE}/string
	@ar -rc ${NAME} ${OBJS_STRING}

write:
	@${MAKE}/write
	@ar -rc ${NAME} ${OBJS_WRITE}

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
