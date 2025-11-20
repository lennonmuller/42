/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:02:17 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/20 18:24:23 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static int	exec_conv(const char spec, va_list args)
{
	if (spec == '%')
		return (write(1, "%", 1));
	else if (spec == 'c')
		return (print_char(args));
	else if (spec == 's')
		return (print_string(args));
	else if (spec == 'p')
		return (print_pointer(args));
	else if (spec == 'd' || spec == 'i')
		return (print_int(args));
	else if (spec == 'u')
		return (print_unsigned(args));
	else if (spec == 'x')
		return (print_hex(args, spec));
	else if (spec == 'X')
		return (print_hex(args, spec));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	if (!format)
		return (0);
	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += exec_conv(format[i], ap);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
