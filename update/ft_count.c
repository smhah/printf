#include "printf.h"
#include <stdio.h>
#include <stdlib.h>

int ft_count(char *arg)
{
    int i;
    int c;
    char *tab;

    i = 0;
    c = 0;
    while(arg[i])
    {
        if (arg[i] == '%')
        {
            c++; 
            i = i + 2;
        }
        else
            i++;
    }
    return(c);
}

int *ft_indices(char *arg)
{
    int i;
    int j;
    int *indices;
    int a;
    int len;

    len = ft_count(arg);
    i = 0;
    j = 0;
    indices = malloc(sizeof(char *) * (len + 1));
    while(arg[i])
    {
        if(arg[i] == '%')
        {
            if((a = ft_isparam(arg[++i])))
                indices[j++] = a;
        }
        i++;
    }
    return(indices);
}