#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

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

// int ft_output(char **tab, char **str, int count)
// {
//     int i;
//     char *s;
//     int j;
//     int sm;

//     i = 0;
//     j = 0;
//     sm = 0;
//     while(i < count)
//     sm = sm + ft_strlen(tab[i++]);
//     s = malloc(ft_strlen(*str) + sm + 1);
//     i = 0;
//     sm = 0;
//     while((*str)[i] != '\0')
//     {
//         while((*str)[i] != '%' && (*str)[i])
//             s[j++] = (*str)[i++];
//         if ((*str)[i] == '\0')
//             break;
//         if(ft_isparam((*str)[++i], 0) >= 0)
//             j = ft_strcpy(&s[j], tab[sm++], j);
//         else
//             s[j++] = (*str)[i];
//             i++;
//     }
//     s[j] = '\0';
//     printf("%s", s);
//     return (ft_strlen(s));
// }



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

// char *ft_percent(void)
// {

// }

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

    str = ft_printhexa(va_arg(n, unsigned long long));
    *tab = ft_strdup("0x");
    *tab = ft_tabjoin(tab, &str);
}

void    ft_valist(va_list n, char *indices, char **etoiles, char **tab)
{
    int i;
    int k;
    int j;

    i = 0;
    k = 0;
    j = 0;
    while (indices[i])
    {     
        if (indices[i] == '9')
            etoiles[k++] = ft_itoa(va_arg(n, int));
        else if (indices[i] == '0' || indices[i] == '4')
		    tab[j++] = ft_itoa(va_arg(n, int));
	    else if(indices[i] == '1')
	 	    tab[j++] = ft_char(va_arg(n, int));
        else if(indices[i] == '2')
	 	    tab[j++] = ft_str(va_arg(n, char *));
	    else if(indices[i] == '3')
	 	    ft_freeadresse(n, &tab[j++]);
	    else if(indices[i] == '5')
	 	    tab[j++] = ft_untoa(va_arg(n, unsigned int));
	    else if(indices[i] == '6')
	 	    tab[j++] = ft_printhexa(va_arg(n, unsigned long long));
	    else if(indices[i] == '7')
	 	    tab[j++] = ft_toper(ft_printhexa(va_arg(n, unsigned long long)));
	    else if(indices[i] == '8')
	        tab[j++] = ft_strdup("%");
        i++;
    }
    tab[j] = NULL;
    etoiles[k] = NULL;
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
        if((*str)[i] != '*')
            newstr[j++] = (*str)[i];
        i++;
    }
    newstr[j] = '\0';
    free(*str);
    return(newstr);
}

int   ft_wichactive(char **flags, char **tab, char *indices, char **str)
{
    int i;
    int j;
    int c;
    int e;
    int s;

    s = 0;
    e = 0;
    j = -1;
    i = 0;
    while(indices[i])
    {
        while ((*str)[e] != '%' && (*str)[e] && (s = s + 1) >= 0)
            printf("%c", (*str)[e++]);
        c = 0;
        if ((indices[i] == '0' || indices[i] == '5' || indices[i] == '6' || indices[i] == '4' || indices[i] == '7' || indices[i] == '3' ) && (j = j + 1) >= 0)
            s = ft_activeflag(&flags[j], &tab[j]) + s;
        else if ((indices[i] == '2') && (j = j + 1) >= 0)
            s = ft_activeflagS(&flags[j], &tab[j]) + s;
        else if (indices[i] == '1' && (j = j + 1) >= 0)
         {
            if(tab[j][0] == '\0' && (s = s + 1))
                printf("%c", '\0');
           s = ft_activeflagC(&flags[j], &tab[j]) + s;
         }
        else if (indices[i] == '8' && (j = j + 1) >= 0)
            s = ft_activeflagpercent(&flags[j], &tab[j]);
        i++;
        if ((*str)[e + 1] != '\0')
            e = e + 2;
        else 
            break;
    }
     while ((*str)[e] != '%' && (*str)[e] && (s = s + 1) >= 0)
            printf("%c", (*str)[e++]);
    return (s);
}
int    ft_subprintf(char *indices, char **flags, va_list n, char **str)
{
    char **tab;
    int count;
    char **etoiles;

    count = ft_count(*str);
    etoiles = (char **)malloc(sizeof(char *) * (ft_countetoiles(*str) + 1 ));
    tab = (char **)malloc(sizeof(char *) * (count + 1));
    ft_valist(n, indices, etoiles, tab);
    ft_modify(flags, etoiles);
    if (ft_strchr(*str, '*'))
        *str = ft_deletoiles(str);
    return (ft_wichactive(flags, tab, indices, str));
    //ft_activeflag(flags, tab, etoiles, indices);
    //ft_activeflagS(flags, tab, etoiles);
    //*str = ft_percent(str);
    //ft_output(tab, str, count)
}