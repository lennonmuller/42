/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:01:01 by lmuler-f          #+#    #+#             */
/*   Updated: 2025/10/21 20:01:01 by lmuler-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char transform(unsigned int i, char c);

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
	{
		printf("'%s' tem %d caracteres. \n", str, len);
	}

	// Example ft_memset
	char	mem[10];
	ft_memset(mem, 'A', 9);
	mem[9] = '\0';
	printf("%s\n", mem);

    // Example ft_bzero
    char    data[] = "Minha string muito loca";
    ft_bzero(data, 3);
    printf("%s\n", data + 3);

    // Example ft_memcpy
    char    cps[] = "Magia da bagaceira negra!";
    char    cpd[30];
    ft_memcpy(cpd, cps, 19);
    cpd[18] = '\0';

    printf("Origem: %s\n", cps);
    printf("Destino: %s\n", cpd);

    // Example ft_memmove
    char    ms[] = "ABCDEFGH";
    printf("Original: %s\n", ms);
    ft_memmove(ms, ms + 2, 6);
    printf("apos memmove: %s\n", ms);

    // Example strlcpy
    printf("\n====STRLCPY:====\n");
    char    origem[] = "Common Core 42";
    char    destino[15];
    unsigned int    r;
    r = ft_strlcpy(destino, origem, sizeof(destino));
    printf("Destino: %s\n", destino);
    printf("comprimento da origem: %u\n", r);

     // Example strlcat
    printf("\n====STRLCAT:====\n");
    char    dcat[] = "blabla";
    char    scat[] = "pipipopopo";
    unsigned int    siz = 25;
    printf("%zu\n", ft_strlcat(dcat, scat, siz));

    // Example toupper
    printf("\n====TOUPPER:====\n");
    int    toup = 'a';
    printf("%c\n", ft_toupper(toup));

    // Example tolower
    printf("\n====TOLOWER:====\n");
    int    tolow = 'A';
    printf("%c\n", ft_tolower(tolow));

    // Example strchr
    printf("\n====STRCHR:====\n");
    const char *strchr = "churrasco com chimarrao";
    char *result;

    result = ft_strchr(strchr, 'm');
    if (result)
        printf("Caractere 'm' encontrado na posicao: %ld\n", result - strchr);
    else
        printf("Caractere 'm' não encontrado.\n");
    
    // Example strrchr
    printf("\n====STRRCHR:====\n");
    const char *strchrr = "churrasco com chimarrao";
    char *resultt;

    resultt = ft_strrchr(strchrr, 'm');
    if (resultt)
        printf("Ultimo caractere 'm' encontrado na posicao: %ld\n", resultt - strchrr);
    else
        printf("Caractere 'm' não encontrado.\n");

    // Example strncmp
    printf("\n====STRNCMP:====\n");
    char	s1[] = "Hello";
	char	s2[] = "Hello World";
	unsigned int x = 7;

	printf("%d\n", ft_strncmp(s1, s2, x));

    // Example memchr
    printf("\n====MEMCHR:====\n");
    char memo[] = "Tung tung tung tung sahur";
    char target = 'h';
    size_t leni = 26;

    void *resulti = ft_memchr(memo, target, leni);
    if (resulti)
        printf("ft_memchr encontrou: '%c' em: %s\n", target, (char *)resulti);
    else
        printf("ft_memchr não encontrou: '%c'\n", target);

    // Example memcmp
    printf("\n====MEMCMP:====\n");
    char blabla[] = "abc";
    char blabla2[] = "acb";

    int resultado = ft_memcmp(blabla, blabla2, sizeof(int));
    printf("%d\n", resultado);

    // Example strnstr
    printf("\n====STRNSTR:====\n");
    printf("%s\n", ft_strnstr("Hello, world!", "world", 13));
    printf("%s\n", ft_strnstr("abcdef", "ass", 6));

    //Example ft_subst
    printf("\n====SUBSTR:====\n");
    printf("%s\n", ft_substr("Churrasco", 1 , 5));
    printf("'%s'\n", ft_substr("42", 0, 2));
	printf("'%s'\n", ft_substr("chimarrao", 3, 50));

    // Example of ft_strjoin
    printf("\n====STRJOIN:====\n");
    char	*s10= "chuchu ";
	char	*s20= "com chimarrao";
	char	*nstr = ft_strjoin(s10, s20);

	printf("%s\n", nstr);
	free(nstr);
    printf("%s\n", ft_strjoin("42", ""));

    // Example of ft_strtrim
    printf("\n====STRTRIM:====\n");
    printf("%s\n", ft_strtrim("xuxuXuxaxuxu", "xu"));

    // Example of ft_split
    printf("\n====SPLIT:====\n");
    char    **split = ft_split("festa da xuxa", ' ');
    printf("%s\n", split[0]);
    printf("%s\n", split[1]);
    printf("%s\n", split[2]);
    printf("%s\n", split[3]);
    free(split[0]);
    free(split[1]);
    free(split[2]);
    free(split[3]);
    free(split);

    // Example of ft_itoa
    printf("\n====ITOA:====\n");
    int it = 42;
    printf("%s\n", ft_itoa(it));

    //Example of ft_strmapi
    printf("\n====STRMAPI:====\n");
    const char  *mamaco = "bezerro manso mama na mae dele e na dos outros";
    char    *modified = ft_strmapi(mamaco, transform);
    if (modified)
    {
        printf("Original: %s\n", mamaco);
        printf("Modificada: %s\n", modified);
        free(modified);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return (0);
}

char transform(unsigned int i, char c)
    {
        if (i % 2 == 0)
            return (c >= 'a' && c <= 'z') ? c - 32 : c;
        else
            return (c >= 'A' && c <= 'Z') ? c + 32 : c;
    }