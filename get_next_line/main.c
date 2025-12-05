#include "get_next_line.h"

/* void	contador_persistente(void)
{
	static int	contador = 0;

	contador++;
	printf("Valor do contador: %d\n", contador);
	
}*/


int	main(void)
{
	int	fd;
	ssize_t	bytes_read;
	char	*linha;

	fd = open("text.txt", O_RDONLY);
	linha = get_next_line(fd);
	if (fd == -1)
	{
		write(2, "Fudeu, deu erro.\n", 17);
		return (1);
	}
	printf("Linha Recebida: %s\n", linha);
	while (1)
	{
		bytes_read = read(fd, linha, 250);
		if (bytes_read == -1)
		{
			write(2, "Fudeu, deu erru.\n", 17);
			close(fd);
			return (1);
		}
		if (bytes_read == 0)
			break;

		linha[bytes_read] = '\0';
		printf("-- Lido %ld bytes --\n%s\n", bytes_read, linha);
	}
	free(linha);
	close(fd);
	return (0);
}
