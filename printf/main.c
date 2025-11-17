
#include "ft_printf.h"

int main(void)
{
    int printed_chars;

    printed_chars = ft_printf("Hello my name is %s I'm %d years old!\n", "Lennon", 28);
    printf("\nTotal printed characters: %d\n", printed_chars);
    
    int	result = printf("How many %s\n", "caracters were written");
    printf("%d characters were written\n", result);
    
    return (0);
}

