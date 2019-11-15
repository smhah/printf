#include "printf.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

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
            while (arg[i] != '%' && arg[i])
                i++;   
        }
    }
    return(c);
}

int *ft_indices(char **str)
{
    int i;
    int j;
    int *indices;
    int a;

    i = 0;
    j = 0;
    indices = malloc(sizeof(int ) * (ft_count(*str) + ft_countetoiles(*str)));
    while((*str)[i] != '\0')
    {
        if((*str)[i++] == '%')
        {
            while ((*str)[i] != '%')
            {
                if((a = ft_isparam((*str)[i], 0)) >= 0)
                {
                    indices[j++] = a;
                    break ;
                }
                else if((*str)[i++] == '*')
                    indices[j++] = 9;
            }
        }
    }
    return(indices);
}
