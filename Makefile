# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 18:19:11 by bhocsak           #+#    #+#              #
#    Updated: 2024/08/23 18:20:14 by bhocsak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES =	\

OBJECTS = $(SOURCES:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	 ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: all

.PHONY: all clean fclean re
