#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buf;
	ssize_t		bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(rest, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			free(rest);
			rest = NULL;
			return (NULL);
		}
		buf[bytes_read] = '\0';
		rest = ft_strjoin_free(rest, buf);
		if (!rest)
			return (NULL);
	}
	free(buf);
	line = extract_line(rest);
	rest = actualize_rest(rest);
	return (line);
}
