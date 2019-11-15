#include <stdio.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

int     ft_counthexa(int n)
{
    int i;
    int e;

    i = 0;
    e = 0;
    while (n > 0)
    {
        e = n % 16;
        n = n / 16;
        if (e < 10)
            i++;
        else
            i++;
    }
    return (i);
}

char    *ft_reverse(char *str)
{
    char *rev;
    int i;
    int j;

    j = 0;
    i = ft_strlen(str);
    rev = malloc(ft_strlen(str) + 1);
    while (--i >= 0)
        rev[j++] = str[i];
    rev[j] = '\0';
    return (rev);
}

char    *ft_printhexa(int n)
{
    char *temp;
    char *rev;
    int e;
    int i;
    
    i = 0;
    temp = malloc(sizeof(char) * (1 + ft_counthexa(n)));
    while (n > 0)
    {
        e = n % 16;
        n = n / 16;
        if (e < 10)
            temp[i++] = e + 48;
        else
            temp[i++] = e + 55;
    }
    temp[i] = '\0';
    e = 0;
    rev = ft_reverse(temp);
    free(temp);;
    return (rev);
}