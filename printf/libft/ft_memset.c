/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:38:07 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/10/23 19:55:41 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*p;

	p = (unsigned char *) s;
	while (n > 0)
	{
		*p++ = (unsigned char) c;
		n--;
	}
	return (s);
}
