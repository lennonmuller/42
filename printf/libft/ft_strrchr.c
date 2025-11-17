/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:47:42 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/03 12:36:51 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned const char	*ptr;
	unsigned const char	*sptr;

	sptr = (unsigned const char *) s;
	ptr = NULL;
	while (*sptr)
	{
		if (*sptr == (unsigned char) c)
			ptr = &*sptr;
		sptr++;
	}
	if (*sptr == (unsigned char) c)
		ptr = &*sptr;
	return ((char *)ptr);
}
