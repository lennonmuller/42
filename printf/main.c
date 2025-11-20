
#include "includes/ft_printf.h"

int	main(void)
{
	int	count_ft;
	int	count_og;
	int	a;

	// int printed_chars;
	// printed_chars = ft_printf("Hello my name is %s I'm %d years old!\n",
	//		"Lennon", 28);
	// printf("Total printed characters: %d\n\n", printed_chars);
	// int	result = printf("How many %s\n", "caracters were written");
	// printf("%d characters were written\n", result);
	// ft_printf("String %-10.5s normal:\n\n", "Hello");
	// ft_printf("String vazia: %s\n\n", "");
	// ft_printf("String NULL: %s\n\n", NULL);
	// ft_printf("Pointer normal: %p\n\n", &printed_chars);
	// ft_printf("Pointer NULL: %p\n\n", NULL);
	// ft_printf("Caractere: %c\n\n", 'A');
	// ft_printf("Porcentagem: %%\n\n");
	// ft_printf("Mix: %c%s%%%c\n\n", 'a', "b", 'c');
	// ft_printf("Int MIN: %d\n\n", -2147483648);
	// ft_printf("Int MAX: %d\n\n", 2147483647);
	// ft_printf("Negativos:%i\n\n", -123456);
	// ft_printf("valor zero: %d\n\n", 0);
	printf("--- TESTANDO REGRESSÃO ---\n");
	// Teste de String
	printf("[Teste de String]\n");
	count_ft = ft_printf("Minha String: %s\n", "Hello World!");
	count_og = printf("Orig. String: %s\n", "Hello World!");
	ft_printf("Chars: ft_printf=%d, printf=%d\n", count_ft, count_og);
	// Teste de String NULA (O teste do avaliador)
	printf("\n[Teste de String Nula]\n");
	count_ft = ft_printf("Minha Nula: %p\n", NULL);
	count_og = printf("Orig. Nula: %p\n", NULL);
	ft_printf("Chars: ft_printf=%d, printf=%d\n", count_ft, count_og);
	// Teste de Char e Porcentagem
	printf("\n[Teste de Char/Percent]\n");
	count_ft = ft_printf("Char: %c, Percent: %%\n", 'A');
	count_og = printf("Orig: %c, Percent: %%\n", 'A');
	ft_printf("Chars: ft_printf=%d, printf=%d\n", count_ft, count_og);
	// Teste de Números (incluindo o matador)
	printf("\n[Teste de Números]\n");
	count_ft = ft_printf("Minha MAX: %d, Minha MIN: %d, Minha Zero: %d\n",
			INT_MAX, INT_MIN, 0);
	count_og = printf("Orig. MAX: %d, Orig. MIN: %d, Orig. Zero: %d\n", INT_MAX,
			INT_MIN, 0);
	ft_printf("Chars: ft_printf=%d, printf=%d\n", count_ft, count_og);
	// Teste de Unsigned e Hex
	printf("\n[Teste de Unsigned/Hex]\n");
	count_ft = ft_printf("Minha Unsigned: %u, Hex min: %x, Hex max: %X\n", 42,
			255, 255);
	count_og = printf("Orig. Unsigned: %u, Hex min: %x, Hex max: %X\n", 42, 255,
			255);
	ft_printf("Chars: ft_printf=%d, printf=%d\n", count_ft, count_og);
	// Teste do Ponteiro
	printf("\n[Teste de Ponteiro]\n");
	count_ft = ft_printf("mPonteiro: %p, mPonteiro Nulo: %p\n", &a, NULL);
	count_og = printf("Orig. Ptr: %p, Orig. Ptr Nulo: %p\n", &a, NULL);
	ft_printf("Chars: ft_printf=%d, printf=%d\n", count_ft, count_og);
	return (0);
}
