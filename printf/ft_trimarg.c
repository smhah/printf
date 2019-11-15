#include <stdio.h>
#include <stdlib.h>
#include "printf.h"
#include <string.h>

int	ft_isflag(int a)
{
	if ((a >= '0' && a <= '9' )|| a == '.' || a == '-' || a == ' ' || a == '+')
		return (1);
	return (0);
}

int ft_isparam(int a, int b)
{
	if (a == '*' && b == 1)
		return(9);
	else if (a == 'd')
		return(0);
	else if(a == 'c')
		return (1);
	else if(a == 's')
		return (2);
	else if(a == 'p')
		return (3);
	else if(a == 'i')
		return (4);
	else if(a == 'u')
		return (5);
	else if(a == 'x')
		return (6);
	else if(a == 'X')
		return (7);
	else if(a == '%')
		return (8);
	return(-1);
}

char *ft_realloc(char **arg)
{
    char *buf;
    int i;

    i = 0;
    buf = malloc(strlen(*arg) + 1);
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
	char *str;
	int i;
	int j;

	str = malloc(sizeof(char) * (strlen(arg) + 1));
	j = 0;
    i = 0;
	while (arg[i])
	{
		while (arg[i] != '%' && arg[i] && (!ft_isflag(arg[i])))
			str[j++] = arg[i++];
        if (arg[i] == '\0')
            break;
			if(arg[i] == '%')
				str[j++] = arg[i++];
        while(ft_isflag(arg[i]))
            i++;
		if(ft_isparam(arg[i], 0) >= 0)
			str[j++] = arg[i++];
 	}
	 str[j] = '\0';
     str = ft_realloc(&str);
    //  printf("%s\n", str);
	//  ft_indices(&str);
	 return (str);
}

// int main ()

// {
//     ft_trimarg("***********************%123123123123123*s**************%123123123123123*d*********");
// }