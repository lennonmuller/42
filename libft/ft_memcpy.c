/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:08:41 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/10/25 12:10:03 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned const char	*s;
	size_t	i;

	if (dst == NULL && src == NULL)
	{
		return (dst);
	}
	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned const char *)src;

	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
