/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:13:40 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/27 17:28:58 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);

	create_list(&list, fd);
}
void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
	{
		free(buf);
		return ;
	}
	new_node->str_buf = buf;
	new_node->next = NULL;

	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}

	temp = *list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}