/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:13:15 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/12/16 19:42:49 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		chars_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[0] == '\0')
		{
			chars_read = read(fd, buffer, BUFFER_SIZE);
			if (chars_read < 0)
				return (free(line), NULL);
			if (chars_read == 0)
				return (line);
			buffer[chars_read] = '\0';
		}
		line = gnl_strjoin(line, buffer);
		if (!line || gnl_strchr(buffer, '\n'))
			break ;
		buffer[0] = '\0';
	}
	update_buffer(buffer);
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
		write(2, "F#rrou, deu erro.\n", 17);
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
