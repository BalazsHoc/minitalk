/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:11:17 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/31 12:11:23 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*mt_strlcpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	main()
{
	struct sigaction	s_term;

	s_term.sa_handler = got_sigint;
	s_term.sa_flags = 0;
	sigemptyset(&s_term.sa_mask);
	sigaction(SIGINT, &s_term, NULL);
	ft_printf("PID: %d\n", getpid());
	handler_server();
	while (1)
		pause();
	return (0);
}
