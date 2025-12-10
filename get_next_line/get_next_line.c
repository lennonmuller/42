/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:13:15 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/12/10 14:16:44 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_null(char *ptr1, char *ptr2)
{
	free(ptr1);
	free(ptr2);
	return (NULL);
}

static char	*read_and_join(int fd, char *stash)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (free_and_null(stash, NULL));
	bytes_read = 1;
	while (!gnl_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_and_null(stash, buffer));
		buffer[bytes_read] = '\0';
		temp = gnl_strjoin(stash, buffer);
		free(stash);
		stash = temp;
		if (!stash)
			return (free_and_null(buffer, NULL));
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_join(fd, stash);
	if (!stash)
		return (NULL);
	line = gnl_get_line(stash);
	if (!line)
	{
		stash = free_and_null(stash, NULL);
		return (NULL);
	}
	stash = gnl_clean_stash(stash);
	return (line);
}
/*int	main(void)
{
	int		fd;
	int		count_line;
	char	*linha = strdup("start");

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Fudeu, deu erro.\n", 17);
		return (1);
	}
	count_line = 1;
	while (linha)
	{
		free(linha);
		linha = get_next_line(fd);
		if (linha)
		{
			printf("Linha %d: %s", count_line, linha);
			count_line++;
		}
	}
	free(linha);
	close(fd);
	return (0);
}*/
