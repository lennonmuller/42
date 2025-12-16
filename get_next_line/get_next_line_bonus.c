/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:31:57 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/12/16 19:41:06 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		chars_read;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[fd][0] == '\0')
		{
			chars_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (chars_read < 0)
				return (free(line), NULL);
			if (chars_read == 0)
				return (line);
			buffer[fd][chars_read] = '\0';
		}
		line = gnl_strjoin(line, buffer[fd]);
		if (!line || gnl_strchr(buffer[fd], '\n'))
			break ;
		buffer[fd][0] = '\0';
	}
	update_buffer(buffer[fd]);
	return (line);
}

//main bonus
// #include "get_next_line_bonus.h"

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	char	*buf = strdup("start");

// 	system(
// 		"git clone https://gist.github.com/6ae63abd1834485811200daefc319b40.git"
// 	);
// 	system("mv './6ae63abd1834485811200daefc319b40/bee movie script' .");
// 	system("cp 'bee movie script' bee_movie_script_1");
// 	system("cp 'bee movie script' bee_movie_script_2");
// 	system("cp 'bee movie script' bee_movie_script_3");
// 	fd1 = open("bee_movie_script_1", O_RDONLY);
// 	fd2 = open("bee_movie_script_2", O_RDONLY);
// 	fd3 = open("bee_movie_script_3", O_RDONLY);
// 	while (buf)
// 	{
// 		free (buf);
// 		buf = get_next_line(fd1);
// 		if (buf)
// 			printf("%s", buf);
// 		free (buf);
// 		buf = get_next_line(fd2);
// 		if (buf)
// 			printf("%s", buf);
// 		free (buf);
// 		buf = get_next_line(fd3);
// 		if (buf)
// 			printf("%s", buf);
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// }