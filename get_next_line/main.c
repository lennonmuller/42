/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:24:31 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/12/09 19:47:59 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/* void	contador_persistente(void)
{
	static int	contador = 0;

	contador++;
	printf("Valor do contador: %d\n", contador);
	
}*/

int	main(void)
{
	int		fd;
	int		count_line;
	char	*linha;

	fd = open("mylord.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Fudeu, deu erro.\n", 17);
		return (1);
	}
	count_line = 1;
	while ((linha = get_next_line(fd)))
	{
		printf("Linha %d: %s", count_line, linha);
		count_line++;
	}
	free(linha);
	close(fd);
	return (0);
}
