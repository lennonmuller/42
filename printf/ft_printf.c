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
#include "libft/libft.h"

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
            format++;
            if (*format == 'c')
            {
                // int c = va_arg(ap, int);
                printf("[TIPO C DETECTADO]");
                count++;
            }
            else if (*format == 's')
            {
                char *s = va_arg(ap, char *);
                ft_putstr_fd(s, 1);
                count++;
            }
            else if (*format == 'p')
            {
                printf("[TIPO P DETECTADO]");
                count++;
            }
            else if (*format == 'd')
            {
                // int i = va_arg(ap, int);
                printf("[TIPO D DETECTADO]");
                count++;
            }
            else if (*format == 'i')
            {
                printf("[TIPO I DETECTADO]");
                count++;
            }
            else if (*format == 'u')
            {
                printf("[TIPO U DETECTADO]");
                count++;
            }
            else if (*format == 'x' || *format == 'X')
            {
                printf("[TIPO X DETECTADO]");
                count++;
            }
            else if (*format == '%')
            {
                putchar('%');
                count++;
            }  
        }
        else
        {
            putchar(*format);
            format++;
            count++;
        }
    }
    va_end(ap);
    return (count);
}
