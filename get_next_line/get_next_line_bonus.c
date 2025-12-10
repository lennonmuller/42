/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:31:57 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/12/10 13:52:58 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_and_join(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = gnl_get_line(stash[fd]);
	if (!line)
	{
		stash[fd] = free_and_null(stash[fd], NULL);
		return (NULL);
	}
	stash[fd] = gnl_clean_stash(stash[fd]);
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