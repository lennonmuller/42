/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:37:49 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/01 13:20:00 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// int	main(void)
// {
// 	char	data[] = "Esta sera a string";
// 	printf("Antes: %s\n", data);

// 	ft_bzero(data, 10);
// 	printf("Depois: %s\n", data);
// 	return (0);
// }