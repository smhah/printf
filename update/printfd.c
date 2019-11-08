/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:09:26 by smhah             #+#    #+#             */
/*   Updated: 2019/11/07 00:46:58 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include <string.h>
#include <stdio.h>
#include "printf.h"

int ft_countarg(char *str, char *needle, char ***tab,int j)
{
	int i;
	int a;
	static int c = 0;

	a = 0;
	i = 0;
	if(j == 3)
				tab[c++] = malloc(sizeof(char *) * (ft_countarg(str, needle, tab, 4) + 1));
	else
	{
		while (str && *str)
		{
			str = strstr(str,needle);
			if (str)
			{
				if (j == 0 || j == 1 || j == 2)
					tab[j][a++] = str;
				str = str + 2;
				i++;
			}
		}
		if (j == 0 || j == 1 || j == 2)
			tab[j][a] = 0;
	}
	return (i);
}

int	*ft_indicess(char ***tab, char **xtab, int *indices)
{
	int i;
	int c;
	int k;

	i = -1;
	while(tab[++i])
    {
    	c = -1;
        while(tab[i][++c])
        {
            k = -1;
            while (xtab[++k])
            {
                if (tab[i][c] == xtab[k])
                    indices[k] = i;
            }
        }
    }
	return(indices);
}

char **ft_tab(char *arg, char **indices)
{
	int i;
    char **xtab;
    char ***tab;

    i = 0;
    tab = malloc(sizeof(char **) * 3);
	//allocate *tab for variables
	i = ft_countarg(arg, "%d", tab, 3) + ft_countarg(arg, "%s", tab, 3) + ft_countarg(arg, "%c", tab, 3);
	//count variables
    i = ft_countarg(arg, "%d", tab, 0) + ft_countarg(arg, "%s", tab, 1) + ft_countarg(arg, "%c", tab, 2);
    indices = malloc(sizeof(int) * i);
    tab[3] = 0;
    xtab = ft_rang(tab, i);
    i = 0;
    printf("\n");
    while(xtab[i])
    {
        printf("%p\n", xtab[i]);
        i++;
    }
    printf("\n");
	*indices = ft_indices(tab, xtab, indices);
    i = 0;
    while (i < 5)
    {
        printf("%d;", indices[i]);
        i++;
    }
        return (xtab);
}

char **ft_flag(char *arg, int count)
{
	int j;
	int i;
	char **tab;
	int save;
	int a;

	count = ft_countarg
	tab = malloc(sizeof(char *) * count + 1)
	while(arg[i])
	{
		save = 0;
		b = 0;
		if (arg[i] == '%')
		{
			save = i;
			while(ft_isflag(arg[i]))
				i++;
			if((a = ft_isparam(arg[i]) >= 0))
			tab[a] = ft_substr(arg, save + 1, i - 1 - save);
			a++;
		}
	}
	tab[a] = NULL;
}
int main ()
{
	//ft_tab("%112dddkfjhsdfjk%cdslgkdfgl%sfldkgjdf%ssdfjdfg%c", 12, 'c', "TRI", 'C');
	//printf("%3654654d\n", 500, 50);
	//ft_flag("%123123d%123234d\n", 500, 50);
	ft_trimarg("asdas%123dsd%---12sdsdsd%.12c");
}