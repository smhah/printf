#include <stdio.h>
#include "libft/libft.h"

int	ft_isflag(int a)
{
	if (ft_isdigit(a) || a == '.' || a == '-' || a == ' ' || a == '+' || a == '*')
		return (1);
	return (0);
}

int ft_isparam(int a)
{
	if (a == 'd')
		return(0);
	else if(a == 'c')
		return (1);
	else if(a == 's')
		return (2);
	else if(a == 'i')
		return (3);
	else if(a == 'p')
		return (4);
	else if(a == 'i')
		return (5);
	else if(a == 'u')
		return (6);
	else if(a == 'x')
		return (7);
	else if(a == 'X')
		return (8);
	else if(a == '%')
		return (9);
	return(-1);
}

char *ft_realloc(char **arg)
{
    char *buf;
    int i;

    i = 0;
    buf = malloc(ft_strlen(*arg) + 1);
    while(arg[0][i])
    {
        buf[i] = arg[0][i];
        i++;
    }
    buf[i] = '\0';
    free(*arg);
    return(buf);
}

char *ft_trimarg(char *arg)
{
	char *newarg;
	int i;
	int j;

	newarg = malloc(sizeof(char) * (ft_strlen(arg) + 1));
	j = 0;
    i = 0;
	while (arg[i])
	{
		while (arg[i] != '%' && arg[i])
			newarg[j++] = arg[i++];
        if (arg[i] == '\0')
            break;
		newarg[j++] = arg[i++];
        while(ft_isflag(arg[i]))
            i++;
		if(ft_isparam(arg[i]) >= 0)
			newarg[j++] = arg[i++];
 	}
	 newarg[j] = '\0';
     newarg = ft_realloc(&newarg);
     printf("%s", newarg);
	 return (newarg);
}

// int main ()

// {
//     ft_trimarg("%--213221300.12dsalah%            ------------321321ceddine%.231123123123cmhah%c");
// }