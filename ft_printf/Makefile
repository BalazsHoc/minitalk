# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 13:34:27 by bhocsak           #+#    #+#              #
#    Updated: 2024/05/21 13:11:05 by bhocsak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = 	ft_printf.c ft_puthex.c ft_putchar_pf.c ft_putstr_pf.c\
		ft_putptr.c ft_putuint.c ft_putnbr_pf.c

OBJECTS = $(SOURCES:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
