/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:33:33 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/31 12:33:35 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>

struct s_data_c
{
	pid_t	server_pid;
	bool	got_signal;
};

void	error_happend(void);
int		sig_handler(int sig);
void	send_bit(char c);
void	handlear_client(char *str);

int		mt_isdigit(int c);
pid_t	mt_atoi(const char *nptr);

#endif