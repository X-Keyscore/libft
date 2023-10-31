# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 06:11:05 by anraymon          #+#    #+#              #
#    Updated: 2023/08/02 13:08:19 by tomoron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

SRCS		=	${wildcard *.c}

SRCS_BONUS	=	

OBJS		= 	${SRCS:.c=.o}

all:			${NAME}

${NAME}:		${OBJS}
			${CC} ${CFLAGS} $^ -o $@

clean:
			rm -f ${OBJS}

fclean:			clean
			rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
