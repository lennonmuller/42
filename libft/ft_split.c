/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:32:54 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/04 18:02:51 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	y;
	
	i = 0;
	str = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	words;
	
	i = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	ft_free(char const **s, int i)
{
	while(s[i] >= i)
	{
		free(s[i]);
		i--;
	}
}