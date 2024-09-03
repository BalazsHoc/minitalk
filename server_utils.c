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

t_server	*g_servers;

void	whole_text_done(void)
{
	int	i;

	i = 0;
	g_servers->message[g_servers->n_char] = '\0';
	printf("%s\n", g_servers->message);
	if (g_servers->message)
	{
		free(g_servers->message);
		g_servers->message = NULL;
	}
	g_servers->n_char = -1;
	g_servers->buf_rs = 0;
}

void	buffer_making(void)
{
	char	*temp;

	if (!g_servers->message
		|| g_servers->n_char == g_servers->buf_rs * g_servers->buffer_size)
	{
		g_servers->buf_rs += 1;
		temp = malloc(sizeof(char) * ((g_servers->buf_rs
						* g_servers->buffer_size) + 1));
		if (!temp)
		{
			if (g_servers->message)
				free(g_servers->message);
			free(g_servers);
			write(2, "Memory allocation error\n", 25);
			exit(1);
		}
		if (g_servers->message)
		{
			mt_strlcpy(temp, g_servers->message, g_servers->n_char);
			free(g_servers->message);
		}
		g_servers->message = temp;
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
				g_servers->message[g_servers->n_char] = c;
			g_servers->n_char += 1;
			buffer_making();
			c = 0;
		}
		kill(siginfo->si_pid, SIGUSR1);
	}
}

void	handler_server(void)
{
	struct sigaction	s_usr;

	g_servers = malloc(sizeof(t_server));
	if (!g_servers)
	{
		write(2, "Memory allocation error\n", 25);
		exit(1);
	}
	g_servers->n_char = 0;
	g_servers->buffer_size = 2;
	g_servers->buf_rs = 0;
	g_servers->message = NULL;
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
	if (g_servers)
	{
		if (g_servers->message)
			free(g_servers->message);
		free(g_servers);
	}
	ft_printf("\n");
	exit(1);
}
