#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "printf.h"

int ft_strcpy(char *str1, char *str2, int j)
{
    int i;
    int a;
 
    a = 0;
    i = ft_strlen(str2) + j;
    while(str2[a])
    {
        str1[a] = str2[a];
        a++;
    }
    return (i);
}

void ft_output(char **tab, char **str, int count)
{
    int i;
    char *s;
    int j;
    int sm;

    i = 0;
    j = 0;
    sm = 0;
    while(i < count)
    sm = sm + ft_strlen(tab[i++]);
    s = malloc(ft_strlen(*str) + sm + 1);
    i = 0;
    sm = 0;
    while((*str)[i] != '\0')
    {
        while((*str)[i] != '%' && (*str)[i])
            s[j++] = (*str)[i++];
        if ((*str)[i] == '\0')
            break;
        if(ft_isparam((*str)[++i]) >= 0)
            j = ft_strcpy(&s[j], tab[sm++], j);
        else
            s[j++] = (*str)[i];
            i++;
    }
    s[j] = '\0';
    printf("%s\n", s);
}

char *ft_str(char *s)
{
    if(s == NULL)
        return s;
    s = ft_strdup(s);
    return(s);
}

char *ft_char(char s)
{
    char *str;

    str = malloc(1);
    str[1] = '\0';
    str[0] = s;
    return(str);
}

void ft_subprintf(int *indices, char **flags, va_list n, char **str)
{
    char **tab;
    int i;
    char **etoiles;
    int j;
    int count;

    count = 0;
    while(tab[i] >= '0' && tab[i] <= '9')
        count++;
    j = 0;
    etoiles = malloc(sizeof(char *) * count);
    tab = malloc(sizeof(char *) * count);
    tab[count] = 0;
    i = 0;
    //printf("T");
    while (i < count)
    {
    if (indices[i] == 9)
        etoiles[i] = ft_itoa(va_arg(n, int));
    if (indices[i] == 0 || indices[i] == 4)
		tab[j++] = ft_itoa(va_arg(n, int));
	else if(indices[i] == 1)
	 	tab[j++] = ft_char(va_arg(n, int));
    else if(indices[i] == 2)
	 	tab[j++] = ft_str(va_arg(n, char *));
	// else if(indices[i] == 3)
	// 	tab[j++] = va_arg();
	else if(indices[i] == 5)
	 	tab[j++] = ft_untoa(va_arg(n, unsigned int));
	else if(indices[i] == 6)
	 	tab[j++] = ft_printhexa(va_arg(n, unsigned int));
	// else if(indices[i] == 7)
	// 	tab[j++] = va_arg();
	// else if(indices[i] == 8)
	// 	tab[j++] = va_arg();
        i++;
    }
    //printf("%s\n", tab[0]);
    ft_activeflag(flags, tab, etoiles);
    ft_output(tab, str, count);
}