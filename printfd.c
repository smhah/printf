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

char **ft_rang(char ***tab, int e);

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
		while (str)
		{
			str = strstr(str,needle);
			if (str)
			{
				if (j == 0 || j == 1 || j == 2)
					tab[j][a] = str;
				str = str + 2;
				i++;
				a++;
			}
		}
		if (j == 0 || j == 1 || j == 2)
			tab[j][a] = 0;
	}
	return (i);
}

char **ft_remplir(char **str, char *arg, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		str[0][j] = arg[j];
		j++;
	}
	return (str);
}

char **ft_tab(char *arg)
{
	int i;
	//int j;
	char **xtab;
	char ***tab;
	//int c;
	
	i = 0;
	tab = malloc(sizeof(char **) * 4);
	ft_countarg(arg,"%d", tab, 3);
	ft_countarg(arg,"%s", tab, 3);
	ft_countarg(arg,"%c", tab, 3);
	i = ft_countarg(arg, "%d", tab, 0) + ft_countarg(arg, "%s", tab, 1) + ft_countarg(arg, "c", tab, 2);
	tab[3] = 0;
	xtab = ft_rang(tab, i);
	return (xtab);
	/*i = 0;
	c = 0;
	while(tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (xtab == tab[i][j] && i == 0)
				xtab[c] = "int";
			else if(xtab == tab[i][j] && i == 1)
				xtab[c] = "char *";
			else if(xtab == tab[i][j] && i == 2)
				xtab[c] = "char";
			c++;
			j++;
		}
		i++;
	}*/
}
/*void	ft_printf(char *arg, ...)
{
	va_list n;
	char	*find;
	char	*str;
	int		len;
	char 	***tab;
	int		a;
	int		b;
	int		c;
	int		i;
	int		compteur;
	int 	somme;

	tab = NULL;
	compteur = 0;
	a = 0;
	if (ft_countarg(arg,"%d"))
		compteur++;
	if (ft_countarg(arg,"%s"))
		compteur++;
	if (ft_countarg(arg,"%d"))
	{	
		b = 0;
		i = 0;
		somme = 0;
		i = ft_countarg(arg,"%d");
		va_start(n, arg);
		tab[a] = malloc(sizeof(char *) * (i + 1));
		while(i > 0)
		{
			tab[a][b] = ft_strdup(ft_itoa(va_arg(n, int)));
			somme = somme + ft_strlen(tab[a][b]);
			b++;
			i--;
		}
		i = ft_countarg(arg,"%d");
		tab[a][b] = 0;
		b = 0;
		len = somme + ft_strlen(arg) - 2 * i;
		str = (char *)malloc(sizeof(char) * (len + 1));
		i = 0;
		while(i < len)
		{
			find = strstr(arg, "%d");
			while (arg != find && *arg)
			{
				str[i] = *arg;
				i++;
				arg++;
			}
			c = 0;
			while(tab[a][b] && tab[a][b][c])
				str[i++] = tab[a][b][c++];
			arg = arg + 2;
			b++;
		}
		str[i] = '\0';
	}
	ft_putstr_fd(str,1);
}*/
int main ()
{
	ft_tab("123%s349%s039%s28%c34%d");
	//printf("%d\n", ft_countarg("numberone:%dnumbertwo%d", "%d"));
}
