/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:02:17 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/12 13:02:17 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

static void parse_flags(const char **format, t_flags *flags);
static t_flags init_flags(void);

static int  parse_and_print(const char **format, va_list args)
{
    t_flags flags;
    int     count;

    (*format)++;
    flags = init_flags();
    parse_flags(format, &flags);
    char spec = **format;
    count = 0;
    if (spec == 'c')
        count += print_char(args);
    else if (spec == 's')
        count += print_string(args);
    else if (spec == 'p')
        count += print_pointer(args);
    else if (spec == 'd' || spec == 'i')
        count += print_int(args);
    else if (spec == 'u')
        count += print_unsigned(args);
    else if (spec == 'x' || spec == 'X')
        count += print_hex(args, spec);
    else if (spec == '%')
        count += write(1, "%", 1);
    (*format)++;
    return (count);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     count;

    count = 0;
    va_start(ap, format);
    while (*format)
    {
        if (*format == '%')
        {
            count += parse_and_print(&format, ap);
        }
        else
        {
            ft_putchar_fd(*format, 1);
            count++;
            format++;
        }
    }
    va_end(ap);
    return (count);
}

static t_flags init_flags(void)
{
    t_flags flags;

    flags.minus = 0;
    flags.zero = 0;
    flags.width = 0;
    flags.dot = 0;
    flags.precision = 0;
    flags.hash = 0;
    flags.space = 0;
    flags.plus = 0;
    return (flags);
}

static void parse_flags(const char **format, t_flags *flags)
{
    while (**format == '-' || **format == '0')
    {
        if (**format == '-')
            flags->minus = 1;
        else if (**format == '0')
            flags->zero = 1;
        (*format)++;
    }
    while (**format >= '0' && **format <= '9')
    {
        flags->width = flags->width * 10 + (**format - '0');
        (*format)++;
    }
    if (**format == '.')
    {
        flags->dot = 1;
        (*format)++;
        while (**format >= '0' && **format <= '9')
        {
            flags->precision = flags->precision * 10 + (**format - '0');
            (*format)++;
        }
    }
}
