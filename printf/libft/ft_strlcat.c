/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:43:40 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/03 13:59:23 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	unsigned int	a;
	unsigned int	b;

	i = 0;
	a = ft_strlen(dst);
	b = ft_strlen(src);
	if (a >= size)
		return (b + size);
	while (src[i] && a + i < size - 1)
	{
		dst[i + a] = src[i];
		i++;
	}
	if (a + i < size)
		dst[a + i] = '\0';
	return (a + b);
}
