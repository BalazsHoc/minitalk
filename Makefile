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
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CFLAGS = -Wall -Werror -Wextra
CC = cc

SRCS_SERVER = server.c server_utils.c
SRCS_CLIENT = client.c client_utils.c
SRCS_SERVER_BONUS = server_bonus.c server_utils_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c client_utils_bonus.c

O_SERVER = $(SRCS_SERVER:.c=.o)
O_CLIENT = $(SRCS_CLIENT:.c=.o)
O_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
O_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all: $(FT_PRINTF) $(SERVER) $(CLIENT)
bonus: $(FT_PRINTF) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(O_SERVER) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(O_SERVER) $(FT_PRINTF) -o $(SERVER)
$(SERVER_BONUS): $(O_SERVER_BONUS) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(O_SERVER_BONUS) $(FT_PRINTF) -o $(SERVER_BONUS)

$(CLIENT): $(O_CLIENT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(O_CLIENT) $(FT_PRINTF) -o $(CLIENT)
$(CLIENT_BONUS): $(O_CLIENT_BONUS) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(O_CLIENT_BONUS) $(FT_PRINTF) -o $(CLIENT_BONUS)

$(FT_PRINTF):
	@$(MAKE) -C ./ft_printf

clean:
	@$(MAKE) clean -C ./ft_printf
	@rm -f $(O_SERVER) $(O_CLIENT)
	@rm -f $(O_SERVER_BONUS) $(O_CLIENT_BONUS)

fclean: clean
	@$(MAKE) fclean -C ./ft_printf
	@rm -f $(SERVER) $(CLIENT)
	@rm -f $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all
rebonus: fclean bonus

.PHONY: all clean fclean re
