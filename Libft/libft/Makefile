SRCS		=	ft_atoi.c ft_tolower.c ft_toupper.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
				ft_isprint.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_isupper.c \
				ft_islower.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcat.c ft_strnstr.c \
				ft_bzero.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
				ft_itoa.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_print_char.c ft_print_hex.c \
				ft_print_int.c ft_print_ptr.c ft_print_str.c ft_print_unsigned_int.c ft_printf.c
OBJS		= ${SRCS:.c=.o}

BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

BONUS_OBJS	= ${BONUS:.c=.o}

NAME		= libft.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
				@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
					ar rc ${NAME} ${OBJS}
					# ranlib ${NAME}

all:			${NAME}

clean:		
			echo "$(OBJS)"
			@${RM} $(OBJS) ${BONUS_OBJS}

fclean:		clean
			@${RM} ${NAME}

re:				fclean all

bonus:		@${OBJS} ${BONUS_OBJS}
			@ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

.PHONY: 	all clean fclean re	bonus
