/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:10:27 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/20 14:18:32 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr_base(unsigned long long nbr, char *base);
int	print_string(va_list args);
int	print_int(va_list args);
int	print_char(va_list args);
int	print_pointer(va_list args);
int	print_unsigned(va_list args);
int	print_hex(va_list args, char spec);

typedef struct s_format_flags
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		hash;
	int		space;
	int		plus;
}	t_flags;

#endif