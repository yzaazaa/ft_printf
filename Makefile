NAME		=	libftprintf.a

SRCS		=	ft_printf.c ft_printf_utils.c

OBJS		=	${SRCS:.c=.o}			

BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

COMP = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(COMP) $(CFLAGS) -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all:	${NAME}

bonus:	$(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)

clean:
	rm -f ${OBJS} $(BONUS_OBJS)

fclean: clean
	rm -f ${NAME}

re: 	fclean all
