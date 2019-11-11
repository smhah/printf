#include "printf.h"
#include <stdio.h>
#include <stdlib.h>

int ft_count(char *arg)
{
    int i;
    int c;

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

int *ft_indices(char **str, int count)
{
    int i;
    int j;
    int *indices;
    int a;

    i = 0;
    j = 0;
    indices = malloc(sizeof(int ) * (count + 1));
    while((*str)[i] != '\0')
    {
        if((*str)[i] == '%')
        {
            if((a = ft_isparam((*str)[i+1])) >= 0)
               indices[j++] = a;
                if(j == count)
                    break;
        }
        i++;
    }
    return(indices);
}