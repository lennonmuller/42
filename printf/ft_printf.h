/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:10:27 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/17 11:10:27 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

int ft_printf(const char *format, ...);
int ft_putnbr_base(unsigned long long nbr, char *base);
int print_string(va_list args);
int	print_int(va_list args);
int print_char(va_list args);
int print_pointer(va_list args);
int print_unsigned(va_list args);
int print_hex(va_list args, char spec);

typedef struct s_format_flags
{
	int		minus;  // Flag '-' (alinhamento à esquerda)
	int		zero;   // Flag '0' (padding com zeros)
	int		width;  // Largura mínima do campo
	int		dot;    // Flag '.' (precisão)
	int		precision; // Valor da precisão
	int		hash;   // Flag '#' (formato alternativo 0x)
	int		space;  // Flag ' ' (espaço para positivos)
	int		plus;   // Flag '+' (sinal para positivos)
}	t_flags;

#endif