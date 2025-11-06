/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:32:54 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/06 18:28:38 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static char		*get_word(char const *s, char c);
static char		**ft_free(char const **s, int i);

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	y;

	if (!s)
		return (NULL);
	str = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	y = 0;
	while (s[i])
		if (s[i] != c)
		{
			str[y] = get_word(&s[i], c);
			if (!str[y])
				return (ft_free((const char **)str, y - 1));
			y++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
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

static char	**ft_free(char const **s, int i)
{
	while (i >= 0)
	{
		free((void *)s[i]);
		i--;
	}
	free(s);
	return (NULL);
}
