/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:39:30 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/03 16:51:32 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		end;
	char	*trim;
	
	i = 0;
	end = ft_strlen(s1);
	if (ft_strlen(s1) == 0)
		return (NULL);
	while (isset(s1[i], set))
		i++;
	while (isset(s1[end - 1], set))
		end--;
	trim = ft_substr(s1, i, end - i);
	return (trim);
}
static int	isset(char c, const char *set)
{
	while (*set && c != *set)
		set++;
	if (c == *set)
		return (1);
	else
		return (0);
}
