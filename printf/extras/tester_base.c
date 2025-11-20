#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int ft_putnbr_base(unsigned int nbr, char *base);

int main(void)
{
    int ret;

    printf("=== TESTE DECIMAL ===\n");
    ret = ft_putnbr_base(12345, "0123456789");
    printf("\nretorno: %d\n\n", ret);

    printf("=== TESTE HEXA MINUSCULO ===\n");
    ret = ft_putnbr_base(3735928559U, "0123456789abcdef");
    printf("\nretorno: %d\n\n", ret);

    printf("=== TESTE HEXA MAIUSCULO ===\n");
    ret = ft_putnbr_base(3735928559U, "0123456789ABCDEF");
    printf("\nretorno: %d\n\n", ret);

    printf("=== TESTE BINARIO ===\n");
    ret = ft_putnbr_base(42, "01");
    printf("\nretorno: %d\n\n", ret);

    printf("=== TESTE OCTAL ===\n");
    ret = ft_putnbr_base(511, "01234567");
    printf("\nretorno: %d\n\n", ret);

    printf("=== TESTE ZERO ===\n");
    ret = ft_putnbr_base(0, "0123456789");
    printf("\nretorno: %d\n\n", ret);

    return (0);
}
