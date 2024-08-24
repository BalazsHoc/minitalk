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

SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
CC = cc

OSERVER = $(server.c=server.o)
OCLIENT = $(client.c=server.o)

all: $(SERVER) $(CLIENT) $(OSERVER) $(OCLIENT)

server.o: server.c
	$(CC) $(CFLAGS) -c $< -o $@

client.o: client.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f server.o
	rm -f client.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: all

.PHONY: all clean fclean re
