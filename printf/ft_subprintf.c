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

// void ft_addnega(char **tab)
// {
//     char s1;
//     char *temp;

//     s1 = ft_strdup("-");
//     temp = *tab
//     tab = strjoin(s1,tab);
// }
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
        if(ft_isparam((*str)[++i], 0) >= 0)
        {
            // if(indices[sm] == 'n')
            //     ft_addnega(tab[sm]);
            j = ft_strcpy(&s[j], tab[sm++], j);
        }
        else
            s[j++] = (*str)[i];
            i++;
    }
    s[j] = '\0';
    printf("%s", s);
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

// char *ft_percent(void)
// {

// }
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
	// else if(indices[i] == 3)
	// 	tab[j++] = va_arg();
	    else if(indices[i] == '5')
	 	    tab[j++] = ft_untoa(va_arg(n, unsigned int));
	    else if(indices[i] == '6')
	 	    tab[j++] = ft_printhexa(va_arg(n, unsigned int));
	// else if(indices[i] == '7')
	// 	tab[j++] = va_arg();
	    else if(indices[i] == '8')
	        tab[j++] = ft_strdup("%");
        if (indices[i] == '0' && (atoi(tab[j-1]) < 0))
            indices[i] = 'n';
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

void    ft_subprintf(char *indices, char **flags, va_list n, char **str)
{
    char **tab;
    int count;
    char **etoiles;

    count = ft_count(*str);
    etoiles = (char **)malloc(sizeof(char *) * (ft_countetoiles(*str) + 1 ));
    tab = (char **)malloc(sizeof(char *) * (count + 1));
    ft_valist(n, indices, etoiles, tab);
    ft_activeflag(flags, tab, etoiles);
    printf("safter is : %s\n", *str);
    if (ft_strchr(*str, '*'))
        *str = ft_deletoiles(str);
    printf("s is :%s\n", *str);
    //*str = ft_percent(str);
    ft_output(tab, str, count);
}