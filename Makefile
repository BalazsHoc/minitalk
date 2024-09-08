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

FT_PRINTF = ft_printf/libftprintf.a

SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
CC = cc

SRCS_SERVER = server.c server_utils.c
SRCS_CLIENT = client.c client_utils.c

O_SERVER = $(SRCS_SERVER:.c=.o)
O_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(FT_PRINTF) $(SERVER) $(CLIENT)

$(SERVER): $(O_SERVER) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(O_SERVER) $(FT_PRINTF) -o $(SERVER)

$(CLIENT): $(O_CLIENT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(O_CLIENT) $(FT_PRINTF) -o $(CLIENT)
:
	@$(MAKE) -C ./libft

$(FT_PRINTF):
	@$(MAKE) -C ./ft_printf

clean:
	@$(MAKE) clean -C ./ft_printf
	@rm -f $(O_SERVER) $(O_CLIENT)

fclean: clean
	@$(MAKE) fclean -C ./ft_printf
	@rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
