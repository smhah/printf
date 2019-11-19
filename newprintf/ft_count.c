#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int r = 0;

int ft_countetoiles(char *arg)
{
    int i;
    int c;

    i = 0;
    c = 0;
    while(arg[i])
    {
        if (arg[i++] == '%')
        {
            while(arg[i] != '%' && arg[i] && (ft_isparam(arg[i], 0) < 0))
            {
                if(arg[i++] == '*')
                    c++;
            }
        }
    }
    return(c); 
}

int ft_count(char *arg)
{
    int i;
    int c;

    i = 0;
    c = 0;
    while(arg[i])
    {
        if (arg[i++] == '%')
        {
            c++;
            if (arg[i] == '%')
                i++;
            while (arg[i] != '%' && arg[i])
                i++;   
        }
    }
    return(c);
}

int ft_fastetoiles(char *indices)
{
    int i;
    int c;

    c = 0;
    i = 0;
    while(indices[i])
    {
        while(indices[i] == '9' && indices[i])
            i++;
        if (indices[i++] == '\0')
            break;
        c++;
    }
    return (c);
}

int ft_fastcount(char *indices)
{
    int i;
    int c;

    i = 0;
    c = 0;
    while(indices[i])
    {
        while(indices[i] == '9' && indices[i++])
            c++;
        if (indices[i++] == '\0')
            break;
    }
    return (c);
}

char *ft_indices(char **str)
{
    int i;
    int j;
    char *indices;
    int a;

    i = 0;
    j = 0;
    indices = malloc(sizeof(int ) * (ft_count(*str) + ft_countetoiles(*str)));
    while((*str)[i] != '\0')
    {
        if((*str)[i++] == '%')
        {

            // if((*str)[i] == '%')
            //     indices[j++] = ft_isparam((*str)[i], 0) + 48;
            // while ((*str)[i] != '%' && (*str)[i])
            while((*str)[i])
            {
                if(((a = ft_isparam((*str)[i], 0)) >= 0)
                        && (indices[j++] = a + 48))
                        {
                            i++;
                            break;
                        }
                else if((*str)[i] == '*')
                {
                    indices[j++] = 9 + 48;
                    i++;
                }
            }
        }
    }
    indices[j] = '\0';
    return (indices);
}
