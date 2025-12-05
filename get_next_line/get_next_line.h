#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char		*str_buf;
	struct s_list	*next;
}			t_list;

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_free(char *rest, char *buffer);
char	*extract_line(const char *rest);
char	*actualize_rest(char *rest);

#endif
