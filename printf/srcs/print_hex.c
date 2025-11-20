/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:19:12 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/19 12:19:12 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(va_list args, char spec)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (spec == 'x')
		return (ft_putnbr_base((unsigned long long)n, "0123456789abcdef"));
	else
		return (ft_putnbr_base((unsigned long long)n, "0123456789ABCDEF"));
}
