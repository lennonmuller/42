/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:00:28 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/10/29 18:55:29 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	
	while ((nptr[i] != '\0' && nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}

	if (nptr[i] != '\0' && (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
		{
			sign = -sign;
		}
	}

	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}