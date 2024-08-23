/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:14:10 by bhocsak           #+#    #+#             */
/*   Updated: 2024/08/09 16:14:22 by bhocsak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_det(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int	ft_count_words(const char *s)
{
	int		words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && !is_det(s[i]))
			words++;
		if (i > 0 && !is_det(s[i]) && is_det(s[i - 1]))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_malloc_cpy(char **new, const char *s)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = -1;
	while (s[++i])
	{
		if ((i == 0 && !is_det(s[i])) || (!is_det(s[i]) && is_det(s[i - 1])))
		{
			j = 0;
			while (s[i + j] && !is_det(s[i + j]))
				j++;
			new[count] = malloc(sizeof(char) * (j + 1));
			if (!new[count])
				return (NULL);
			new[count++][j] = '\0';
			j = 0;
			while (s[i] && !is_det(s[i]))
				new[count - 1][j++] = s[i++];
		}
	}
	return (new);
}

static void	ft_merror(char **new)
{
	size_t	i;

	i = 0;
	while (new[i])
	{
		free(new[i]);
		new[i] = NULL;
		i++;
	}
	free(new);
	new = NULL;
}

char	**ft_split(char *s)
{
	char	**new;
	int		wordcount;

	wordcount = ft_count_words(s);
	if (!wordcount)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	new = malloc(sizeof(char *) * (wordcount + 1));
	if (!new)
		exit(2);
	if (ft_malloc_cpy(new, s))
		new[wordcount] = NULL;
	else
	{
		ft_merror(new);
		return (NULL);
	}
	return (new);
}
