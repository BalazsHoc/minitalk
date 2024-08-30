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

static int	is_det(char s1, char c)
{
	if (s1 == c)
		return (1);
	return (0);
}

static int	ft_count_words(const char *s1, char c)
{
	int		words;
	size_t	i;

	words = 0;
	i = 0;
	while (s1[i])
	{
		if (i == 0 && !is_det(s1[i], c))
			words++;
		if (i > 0 && !is_det(s1[i], c) && is_det(s1[i - 1], c))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_malloc_cpy(char **new, const char *s1, char c)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = -1;
	while (s1[++i])
	{
		if ((i == 0 && !is_det(s1[i], c))
			|| (!is_det(s1[i], c) && is_det(s1[i - 1], c)))
		{
			j = 0;
			while (s1[i + j] && !is_det(s1[i + j], c))
				j++;
			new[count] = malloc(sizeof(char) * (j + 1));
			if (!new[count])
				return (NULL);
			new[count++][j] = '\0';
			j = 0;
			while (s1[i] && !is_det(s1[i], c))
				new[count - 1][j++] = s1[i++];
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

char	**ft_split(char const *s1, char c)
{
	char	**new;
	int		wordcount;

	wordcount = ft_count_words(s1, c);
	if (!wordcount)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	new = malloc(sizeof(char *) * (wordcount + 1));
	if (!new)
		exit(2);
	if (ft_malloc_cpy(new, s1, c))
		new[wordcount] = NULL;
	else
	{
		ft_merror(new);
		return (NULL);
	}
	return (new);
}
