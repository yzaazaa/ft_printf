# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 00:21:38 by yzaazaa           #+#    #+#              #
#    Updated: 2023/11/16 05:28:38 by yzaazaa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c helpers.c helpers_ptr.c ft_putnbr.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

CC = cc

all : $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $< -fsanitize=address

$(NAME) : $(OBJS) 
	ar rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : fclean clean