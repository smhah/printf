#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>
#include "printf.h"

int ft_printf(const char *arg, ...)
{
    char *str;
    int  *indices;
    //char **flags;
    int  count;
    va_list n;

    va_start(n, arg);
    str = ft_trimarg((char *)arg);
    count = ft_count(str);
    //printf("%d", count);
    //printf("%s\n",str);
    indices = ft_indices(&str, count);
    //flags = ft_flag(arg, str, indices);
    ft_subprintf(indices, count, n, &str);
}

int main()
{
    ft_printf("salaheddine%-------------234234234120xmhah",35732);
    //printf("%saaa", NULL);
    return(0);
}