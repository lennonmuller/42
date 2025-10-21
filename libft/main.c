#include <stdio.h>
#include "libft.h"

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_strlen(char *str);

int main()
{
    // Example usage of ft_isalpha
    char	ch = 'A';
    if (ft_isalpha(ch))
        printf("%c is an alphabetic character.\n", ch);
    else
        printf("%c is not an alphabetic character.\n", ch);

    // Example usage of ft_isdigit
    char	digit = '5';
    if (ft_isdigit(digit))
        printf("%c is a digit.\n", digit);
    else
        printf("%c is not a digit.\n", digit);

    // Example usage of ft_isalnum
    char	alnum = 'b';
    if (ft_isalnum(alnum))
	    printf("%c is alfanum. \n", alnum);
    else
	    printf("%c is not alfanum. \n", alnum);

    // Example ft_isascii
    int	isas = 128;
    if (ft_isascii(isas))
        printf("%c is ascii. \n", isas);
    else
        printf("%c is not ascii. \n", isas);

    // Example ft_isprint
    int	isp = 33;
    if (ft_isprint(isp))
        printf("%c is printable. \n", isp);
    else
        printf("%c is not printable. \n", isp);

    // Example ft_strlen
    char	str[] = "magia negra";
    int	len;
    len = ft_strlen(str);
    if (ft_strlen(str))
        printf("'%s' tem %d caracteres. \n", str, len);
    return (0);
}
