#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>
#include "printf.h"

void    ft_delzero(char **str)
{
    int i;
    int j;
    char *newstr;

    i = 0;
    j = 0;
    newstr = malloc(ft_strlen(*str));
    while((*str)[++i])
    {
        newstr[j++] = (*str)[i];
    }
    newstr[j] = '\0';
    free(*str);
    *str = newstr;
}

void    ft_ignore(char **flags)
{
    int i;
    int j;

    i = 0;
  
    while(flags[i])
    {
        j = 0;
        if(flags[i][j] == '0')
        {
            while(flags[i][++j])
            {
                if (flags[i][j] == '.')
                    ft_delzero(&flags[i]); 
            }
        }
        i++;
    }
}

int ft_printf(const char *arg, ...)
{
    char *str;
    char  *indices;
    char **flags;
    va_list n;

    va_start(n, arg);
    str = ft_trimarg((char *)arg);
    indices = ft_indices(&str);
    flags = ft_flag((char *)arg, str);
    ft_ignore(flags);
    ft_subprintf(indices, flags, n, &str);
    return(1);
}

int main()
{
    //DON't FORGET ERROR NEGATIVE
    ft_printf("%-*.*ds\n", -3, 5, 9);
    printf("%*.*d\n", -3, 5, 9);
    //printf("\n");
    //printf("%s", "%d");
    //printf("\n");
    //printf("%3.2d", 5);
    //printf("%saaa", NULL);
 
    return(0);
}