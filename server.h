/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:33:41 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/31 12:33:42 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>

struct s_data_s
{
	pid_t	c_pid;
	char	*message;
	int		n_char;
	int		buffer_size;
	int		buf_rs;
};

void	whole_text_done(void);
void	buffer_making(void);
void	get_bit(int sig, siginfo_t	*siginfo, void *context);
void	handler_server(void);
void	got_sigint(int sig);

char	*mt_strlcpy(char *dest, char *src, int len);

#endif