#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int g;
int g_j;
int g_i;
int g_k;

int ft_strcpy(char *str1, char *str2, int j)
{
    int i;
    int a;
 
    a = 0;
    i = ft_strlen(str2) + j;
    // if (indices[i] = 'c' && *tab = '\0')
    //     str1[a] = *tab;
    while(str2[a])
    {
        str1[a] = str2[a];
        a++;
    }
    return (i);
}

char *ft_str(char *s)
{
    if(s == NULL)
        return (ft_strdup("(null)"));
    s = ft_strdup(s);
    return(s);
}

char *ft_char(char s)
{
    char *str;

    str = malloc(1);
    if (s == '\0')
    {
        *str = '\0';
        return (str);
    }
    str[1] = '\0';
    str[0] = s;
    return(str);
}


char *ft_toper(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if(ft_isalpha(str[i]))
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}

void ft_freeadresse(va_list n, char **tab)
{
    char *str;

    str = ft_printadresse(va_arg(n, unsigned long long));
    *tab = ft_strdup("0x");
    *tab = ft_tabjoin(tab, &str);
}

void    ft_valist(va_list n, char *indices, char **etoiles, char **tab)
{
    while (indices[g_i])
    {     
        if (indices[g_i] == '9')
            etoiles[g_k++] = ft_itoa(va_arg(n, int));
        else if (indices[g_i] == '0' || indices[g_i] == '4')
		    tab[g_j++] = ft_itoa(va_arg(n, int));
	    else if(indices[g_i] == '1')
	 	    tab[g_j++] = ft_char(va_arg(n, int));
        else if(indices[g_i] == '2')
	 	    tab[g_j++] = ft_str(va_arg(n, char *));
	    else if(indices[g_i] == '3')
	 	    ft_freeadresse(n, &tab[g_j++]);
	    else if(indices[g_i] == '5')
	 	    tab[g_j++] = ft_untoa(va_arg(n, unsigned int));
	    else if(indices[g_i] == '6')
	 	    tab[g_j++] = ft_printhexa(va_arg(n, unsigned long long));
	    else if(indices[g_i] == '7')
	 	    tab[g_j++] = ft_toper(ft_printhexa(va_arg(n, unsigned long long)));
	    else if(indices[g_i] == '8')
	        tab[g_j++] = ft_strdup("%");
        g_i++;
    }
    tab[g_j] = NULL;
    etoiles[g_k] = NULL;
}

char    *ft_deletoiles(char **str)
{
    char *newstr;
    int i;
    int j;

    j = 0;
    i = 0;
    newstr = malloc(ft_strlen(*str) + 1);
    while((*str)[i])
    {
        while((*str)[i] && (*str)[i] != '%')
            newstr[j++] = (*str)[i++];
            newstr[j++] = (*str)[i];
        if ((*str)[i++])
        {
            while((*str)[i] && (ft_isparam((*str)[i], 0)) < 0)
                    i++;
            if ((*str)[i] == '%')
                newstr[j++] = (*str)[i++];
        }
    }
    newstr[j] = '\0';
    free(*str);
    return(newstr);
}

int ft_checkindices1(char *indices, int i)
{
    if (indices[i] == '0' || indices[i] == '5' ||
     indices[i] == '6' || indices[i] == '4' ||
      indices[i] == '7' || indices[i] == '3' )
      return (1);
      return (0);
}

int   ft_wichactive(char **flags, char **tab, char *indices, char **str)
{
    int i;
    int j;
    int e;
    int s;

    s = 0;
    e = 0;
    j = -1;
    i = 0;
    while(indices[i])
    {
        while ((g == 0) && (*str)[e] != '%' && (*str)[e] && ((s = s + 1) >= 0))
         write(1,&(*str)[e++], 1);
        if (ft_checkindices1(indices, i) && (j = j + 1) >= 0)
            s = ft_activeflag(&flags[j], &tab[j]) + s;
        else if ((indices[i] == '2') && (j = j + 1) >= 0)
            s = ft_activeflagS(&flags[j], &tab[j]) + s;
        else if (indices[i] == '1' && (j = j + 1) >= 0)
           s = ft_activeflagC(&flags[j], &tab[j]) + s;
        else if (indices[i] == '8' && (j = j + 1) >= 0)
            s = ft_activeflagpercent(&flags[j], &tab[j]) + s;
        if ((*str)[e + 2] != '\0' && g == 0)
            e = e + 2;
        g = (indices[i++] == '9' ? 1 : 0);
    }
     while ((*str)[e] != '%' && (*str)[e] && (s = s + 1) >= 0)
            write(1,&(*str)[e++], 1);
    return (s);
}

void freeall(char **tab, char **flags, char **str, char **indices)
{
    int i;

    i = 0;
    while(tab[i])
        free(tab[i++]);
    free(tab);
    i = 0;
    while(flags[i])
        free(flags[i++]);
    free(flags);
    free(*str);
    free(*indices);
}
int    ft_subprintf(char *indices, char **flags, va_list n, char **str)
{
    char **tab;
    int count;
    char **etoiles;

    count = ft_count(*str);
    etoiles = (char **)malloc(sizeof(char *) * (ft_countetoiles(*str) + 1 ));
    tab = (char **)malloc(sizeof(char *) * (count + 1));
    g_i = 0;
    g_k = 0;
    g_j = 0;
    ft_valist(n, indices, etoiles, tab);
    ft_modify(flags, etoiles);
    count = 0;
    if (ft_strchr(*str, '*'))
        *str = ft_deletoiles(str);
    g = 0;
    g_i = 0;
    g_j = 0;
    g_k = 0;
    count = ft_wichactive(flags, tab, indices, str);
    free(etoiles);
    freeall(tab, flags, str, &indices);
    return (count);
}
