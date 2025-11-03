/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:43:58 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/03 15:11:52 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	len1;
	size_t	len2;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2;
	nstr = ft_calloc(len + 1, sizeof(char));
	if (!nstr)
		return (NULL);
	ft_strlcpy(nstr, s1, len1 + 1);
	ft_strlcat(nstr, s2, len + 1);
	return (nstr);
}
