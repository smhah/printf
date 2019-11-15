#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>
#include "printf.h"

int ft_printf(const char *arg, ...)
{
    char *str;
    char  *indices;
    char **flags;
    va_list n;

    va_start(n, arg);
    str = ft_trimarg((char *)arg);
    //printf("%d", count);
    //printf("%s\n",str);
    indices = ft_indices(&str);
    flags = ft_flag((char *)arg, str);
    ft_subprintf(indices, flags, n, &str);
    return(1);
}

int main()
{
    ft_printf("salah%*d%*d",12,17,3,150);
    //printf("%saaa", NULL);
    return(0);
}