# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 12:41:46 by nnemeth           #+#    #+#              #
#    Updated: 2023/02/21 15:39:12 by nnemeth          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB			= Libft/libft/libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g3 #-fsanitize=address 

SRCS		= $(wildcard *.c)

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

NAME		= miniRT
 
FRAMEWORK	= -framework OpenGL -framework AppKit

MLXPATH		= ./minilibx/

INCLUDEMLX	= -I ${MLXPATH}

LMLX		= -L ${MLXPATH} -lmlx

all:	${NAME}
.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		@$(MAKE) -C ${MLXPATH}
		@$(MAKE) -C ./Libft/libft
		@$(CC) $(CFLAGS) $(FRAMEWORK) $(SRCS) $(LMLX) $(LIB) -o $(NAME)

clean:
		echo "$(OBJS)"
		${RM} $(OBJS)
		@make clean -C Libft/libft

fclean:	clean
		${RM} ${NAME}
		@make fclean -C Libft/libft

re:		fclean all