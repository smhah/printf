#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>
#include "ft_printf.h"

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

void    ft_ignore(char **flags, char *indices)
{
    int i;
    int j;

    i = 0;
  
    while(flags[i])
    {
        j = 0;
        if(flags[i][j] == '0' && indices[i] != '8')
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
    ft_ignore(flags, indices);
    return(ft_subprintf(indices, flags, n, &str));
}

// int main()
//  {
//       int j;
//      int i;
//     char *p;

//     // FOR P USE SIZE_T;
//     p = NULL;
//     // DON't FORGET ERROR NEGATIVE
//     // j = ft_printf("| %s\n,  NULL);
//     // j = ft_printf(" hello ca%----4c %1c va %10c%-c ??\n" ,'\0', '\n', (char)564, 0);
//     // ft_printf("%*.*X\n", 1, 0, 10);
//     j = ft_printf("hello ca%----6c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
//     printf("%d\n", j);
//     // printf("%-10cd\n", 0);
//     // ft_printf("%-10cd\n", 0);
//     // i = printf(" hello ca%----6c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
    

//     // //i = printf("%pb\n");
//     i = printf("hello ca%----6c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
//     printf("%d\n", i);
//     // ft_printf("|%60.syo\n", "s");
//     // printf("|%*d|\n", 5, 2);
//     // printf("\n");
//     // printf("%s", "%d");
//     // printf("\n");
//         // ft_printf("s%1s%-100c\n","salah", 'A' );
//         // //printf("\n");
//         // printf("s%1s%-100c","salah", 'A' );
//         // j = printf("dsfsdfdsfdsfdsf%c\n", 'A');
//         // printf("%d\n", i);
//     // printf("%saaa", NULL);
//     return(0);
//  }
