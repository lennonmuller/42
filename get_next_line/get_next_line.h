/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:19:03 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/12/09 19:40:34 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_get_line(const char *stash);
char	*gnl_clean_stash(char *stash);

#endif