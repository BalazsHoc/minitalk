/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:46:47 by bhocsak           #+#    #+#             */
/*   Updated: 2024/09/03 12:46:49 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

struct s_data_s	g_server;

void	whole_text_done(void)
{
	int	i;

	i = 0;
	g_server.message[g_server.n_char] = '\0';
	ft_printf("%s\n", g_server.message);
	if (g_server.message)
	{
		free(g_server.message);
		g_server.message = NULL;
	}
	g_server.n_char = -1;
	g_server.buf_rs = 0;
}

void	buffer_making(void)
{
	char	*temp;

	if (!g_server.message
		|| g_server.n_char == g_server.buf_rs * g_server.buffer_size)
	{
		g_server.buf_rs += 1;
		temp = malloc(sizeof(char) * ((g_server.buf_rs
						* g_server.buffer_size) + 1));
		if (!temp)
		{
			if (g_server.message)
				free(g_server.message);
			write(2, "Memory allocation error\n", 25);
			exit(1);
		}
		if (g_server.message)
		{
			mt_strlcpy(temp, g_server.message, g_server.n_char);
			free(g_server.message);
		}
		g_server.message = temp;
	}
}

void	get_bit(int sig, siginfo_t	*siginfo, void *context)
{
	static int				i;
	static unsigned char	c;

	(void)context;
	if (!i)
		i = 8;
	if (i)
	{
		if (sig == SIGUSR1)
			c = c * 2 + 1;
		else if (sig == SIGUSR2)
			c = c * 2 + 0;
		i--;
		if (i == 0)
		{
			if (c == '\0')
				whole_text_done();
			else
				g_server.message[g_server.n_char] = c;
			g_server.n_char += 1;
			buffer_making();
			c = 0;
		}
		kill(siginfo->si_pid, SIGUSR1);
	}
}

void	handler_server(void)
{
	struct sigaction	s_usr;

	g_server.n_char = 0;
	g_server.buffer_size = 256;
	g_server.buf_rs = 0;
	g_server.message = NULL;
	buffer_making();
	s_usr.sa_sigaction = get_bit;
	s_usr.sa_flags = SA_SIGINFO;
	sigemptyset(&s_usr.sa_mask);
	sigaction(SIGUSR1, &s_usr, NULL);
	sigaction(SIGUSR2, &s_usr, NULL);
}

void	got_sigint(int sig)
{
	(void)sig;
	if (g_server.message)
		free(g_server.message);
	ft_printf("\n");
	exit(1);
}
