#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	cc;

	if (!s)
		return (NULL);
	i = 0;
	cc = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (cc == '\0')
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_free(char *rest, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!rest)
	{
		rest = malloc(1);
		if (!rest)
			return (NULL);
		rest[0] = '\0';
	}
	new_str = malloc(ft_strlen(rest) + ft_strlen(buffer) + 1);
	if (!new_str)
		return (free(rest), NULL);
	i = -1;
	while (rest[++i])
		new_str[i] = rest[i];
	j = 0;
	while (buffer[j])
		new_str[i++] = buffer[j++];
	new_str[i] = '\0';
	free(rest);
	return (new_str);
}

char	*extract_line(const char *rest)
{
	size_t	i;
	char	*line;

	if(!rest || !*rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*actualize_rest(char *rest)
{
	size_t	i;
	size_t	j;
	char	*new_rest;

	if (!rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	new_rest = (char *)malloc(sizeof(char) * (ft_strlen(rest) - (i + 1) + 1));
	if (!new_rest)
		return (NULL);
	i++;
	j = 0;
	while (rest[i])
		new_rest[j++] = rest[i++];
	new_rest[j] = '\0';
	free(rest);
	return (new_rest);
}
