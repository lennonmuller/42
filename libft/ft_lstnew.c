/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:01:42 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/10 17:15:41 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
// Examplo
/*
#include <stdio.h>

int	main(void)
{
	t_list	*node;

	node = ft_lstnew("Hello, World!");
	if (node)
	{
		printf("Node content: %s\n", (char *)node->content);
		free(node);
	}
	return (0);
}
*/