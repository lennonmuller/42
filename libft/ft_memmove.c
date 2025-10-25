/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:27:23 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/10/25 14:38:42 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned const char	*s;
	size_t	i;

	if (!dst && !src)
	{
		return (dst);
	}
	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned const char *)src;

	if (d > s)
	{
		while (len > 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
