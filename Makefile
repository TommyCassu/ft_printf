# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toto <toto@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 17:43:09 by marvin            #+#    #+#              #
#    Updated: 2024/12/01 00:22:10 by toto             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_printf.c ft_printf_utils_alnum.c ft_printf_utils_hex.c

SRCS 		= ${SRC}

OBJS		= ${SRCS:.c=.o}

INCLUDES	= ./includes

LIBFT		= libft

NAME		= libftprintf.a

AR			= ar rc

RM			= rm -f

RANLIB		= ranlib

GCC			= gcc

CFLAGS		= -Wall -Werror -Wextra

all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c -I ${INCLUDES} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			${AR} ${NAME} ${OBJS}
			${RANLIB} ${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all
			
.PHONY:		all clean fclean re
