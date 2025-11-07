/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:32:54 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/07 13:32:11 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static char		*get_word(char const *s, char c);
static char		**free_split(char const **s, int i);
static char		**fill_split(char **split, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	str = fill_split(str, s, c);
	return (str);
}

static size_t	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			words++;
		else if (i > 0 && s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

static char	*get_word(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	return (word);
}

static char	**free_split(char const **s, int i)
{
	while (i >= 0)
	{
		free((void *)s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

static char	**fill_split(char **split, char const *s, char c)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			split[y] = get_word(&s[i], c);
			if (!split[y])
				return (free_split((const char **)split, y - 1));
			y++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (split);
}
