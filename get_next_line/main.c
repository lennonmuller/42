#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		count_line;
	char	*linha = strdup("start");

	system(
		"curl -o bible.txt https://raw.githubusercontent.com/mxw/grmr/master/src/finaltests/bible.txt"
	);

	fd = open("bible.txt", O_RDONLY);
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
}

