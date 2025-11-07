/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:32:00 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/07 12:20:53 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	str = ft_calloc(sizeof(char), (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
// char transform(unsigned int i, char c)
// {
//     if (i % 2 == 0)
//         return ((c >= 'a' && c <= 'z') ? c - 32 : c);
//     else
//         return ((c >= 'A' && c <= 'Z') ? c + 32 : c);
// }

// int main(void)
// {
//     const char *original = "Hello, World!";
//     char *modified = ft_strmapi(original, transform);

//     if (modified)
//     {
//         printf("Original: %s\n", original);
//         printf("Modified: %s\n", modified);
//         free(modified);
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }
//     return (0);
// }
