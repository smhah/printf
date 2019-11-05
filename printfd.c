/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:09:26 by smhah             #+#    #+#             */
/*   Updated: 2019/11/05 01:43:47 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include <string.h>
#include <stdio.h>

int ft_countarg(char *str, char *needle)
{
	int i;

	i = 0;
	while (str)
	{
		str = strstr(str,needle);
		if (str)
		{
			str = str + 2;
			i++;
		}
	}
	return (i);
	printf("|%d|", i);
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

void	ft_printf(char *arg, ...)
{
	va_list n;
	char	*find;
	char	*str;
	int		len;
	char 	**tab;
	int		a;
	int		b;
	int		i;
	
	b = 0;
	a = 0;
	tab = NULL;
	i = 0;
	i = ft_countarg(arg,"%d");
	va_start(n, arg);
	tab = malloc(sizeof(char *) * (i + 1));
	while(i > 0)
	{
		tab[a] = ft_strdup(ft_itoa(va_arg(n, int)));
		b = b + ft_strlen(tab[a]);
		a++;
		i--;
	}
	i = ft_countarg(arg,"%d");
	tab[a] = 0;
	a = 0;
	len = b + ft_strlen(arg) - 2 * i;
	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while(i < len - 1)
	{
		find = strstr(arg, "%d");
		while (arg != find && *arg)
		{
			str[i] = *arg;
			i++;
			arg++;
		}
		b = 0;
		while(tab[a] && tab[a][b])
			str[i++] = tab[a][b++];
		arg = arg + 2;
		a++;
	}
	str[i] = '\0';
	ft_putstr_fd(str,1);
}

int main ()
{
	ft_printf("%dmhah%d", 10+20, 2000);
	//printf("%d\n", ft_countarg("numberone:%dnumbertwo%d", "%d"));
}
