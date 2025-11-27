/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:42:05 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/27 14:26:54 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	fd_terminal(char c);
void	fd_file(char c);

int	main(void)
{
	int	fd;
	char	buf[250];
	int	chars_read;
	
	fd = open("mylord.txt", O_RDONLY);
	
	while ((chars_read = read(fd, buf, 20)))
	{
		buf[chars_read] = '\0';
		printf("buf-> %s\n", buf);
	}
	// fd_terminal('F');
	// fd_file('C');
}

void	fd_terminal(char c)
{
	write(1, &c, 1);
}

void	fd_file(char c)
{
	int	fd;
	
	fd = open("text.txt", O_RDWR);
	
	if (fd > 0)
	{
		write(fd, &c, 1);
	}
	else
		write(2, "Text nao encontrado", 20);
}