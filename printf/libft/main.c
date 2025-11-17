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
void    test_iteri(unsigned int i, char *c);
void *dup_content(void *c);
void print_node(void *content);
void del_content(void *c);

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

    printf("\n====SUBSTR:====\n");
    char *sub1 = ft_substr("Churrasco", 1 , 5);
    char *sub2 = ft_substr("42", 0, 2);
    char *sub3 = ft_substr("chimarrao", 3, 50);
    printf("%s\n", sub1);
    printf("'%s'\n", sub2);
    printf("'%s'\n", sub3);
    free(sub1);
    free(sub2);
    free(sub3);

    // Example atoi
    printf("\n====ATOI:====\n");
    char numstr1[] = "42";
    char numstr2[] = "   -123abc";
    char numstr3[] = "9999999999";
    printf("%d\n", ft_atoi(numstr1));
    printf("%d\n", ft_atoi(numstr2));
    printf("%d\n", ft_atoi(numstr3));

    // Example calloc
    printf("\n====CALLOC:====\n");
    int *arr = (int *)ft_calloc(5, sizeof(int));
    if (arr)
    {
        for (int i = 0; i < 5; i++)
            printf("%d ", arr[i]);
        printf("\n");
        free(arr);
    }

    // Example strdup
    printf("\n====STRDUP:====\n");
    char *original = "duplicar";
    char *copy = ft_strdup(original);
    printf("Original: %s | Copia: %s\n", original, copy);
    free(copy);

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
    char    **split = ft_split("spithoferi splichofai he", ' ');
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

    //Example of Iteri
    printf("\n====STRITERI:====\n");
    char    s[] = "eai mae";
    ft_striteri(s, test_iteri);
    printf("%s\n", s);

    printf("\n====FD:====\n"); 
    // FD test
    int fd = open("file.txt", O_RDWR, O_CREAT);
    ft_putchar_fd('c', 1);
    ft_putchar_fd('\n', 1);
    ft_putchar_fd('b', fd);
    ft_putchar_fd('\n', fd);
 /*    char puts[] = "labubu\n"; */
    ft_putstr_fd("Vamos ", fd);
    ft_putendl_fd("Sao Paulo!!", fd);
    ft_putnbr_fd(15632, 1);



    printf("\n====BONUS LISTAS:====\n");

    // ft_lstnew
    t_list *node1 = ft_lstnew(ft_strdup("Primeiro"));
    printf("Node1 content: %s\n", (char *)node1->content);

    // ft_lstadd_front
    t_list *node2 = ft_lstnew(ft_strdup("Segundo"));
    ft_lstadd_front(&node1, node2);
    printf("Primeiro da lista agora: %s\n", (char *)node1->content);

    // ft_lstsize
    printf("Tamanho da lista: %d\n", ft_lstsize(node1));

    // ft_lstlast
    t_list *last = ft_lstlast(node1);
    printf("Ultimo elemento: %s\n", (char *)last->content);

    // ft_lstadd_back
    t_list *node3 = ft_lstnew(ft_strdup("Terceiro"));
    ft_lstadd_back(&node1, node3);
    printf("Novo ultimo: %s\n", (char *)ft_lstlast(node1)->content);
    printf("Tamanho atualizado: %d\n", ft_lstsize(node1));

    // // ft_lstdelone
    // printf("Testando lstdelone em node3\n");
    // ft_lstdelone(node3, del_content);

    // ft_lstiter
    printf("Iterando lista:\n");
    ft_lstiter(node1, print_node);

    // ft_lstmap
    printf("Mapeando lista (duplicar strings):\n");
    t_list *mapped = ft_lstmap(node1, dup_content, del_content);
    ft_lstiter(mapped, print_node);

    // ft_lstclear
    ft_lstclear(&node1, del_content);
    ft_lstclear(&mapped, del_content);

    return (0);
}

char transform(unsigned int i, char c)
{
    if (i % 2 == 0)
        return (c >= 'a' && c <= 'z') ? c - 32 : c;
    else
        return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

void    test_iteri(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = *c - 32;
}

void print_node(void *content)
{
    printf("%s\n", (char *)content);
}
void *dup_content(void *c)
{ 
    return ft_strdup((char *)c);
}
void del_content(void *c)
{
    free(c);
}
