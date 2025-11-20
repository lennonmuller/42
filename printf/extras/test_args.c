/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:22:48 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/11/12 11:22:48 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void    minha_func_variadica(int num_args, ...)
{
    va_list arguments;
    int i;
    int valor_int;

    printf("Numero de argumentos esperados %d\n", num_args);
    i = 0;
    va_start(arguments, num_args);
    while (i < num_args)
    {
        valor_int = va_arg(arguments, int);
        printf("Argumento %d: %d\n", i, valor_int);
        i++;
    }
    va_end(arguments);
}
