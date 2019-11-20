/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:23:42 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 13:44:26 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_j;

int		ft_isflag(int a)
{
	if (ft_isdigit(a) || a == '.' || a == '-' || a == '+' || a == '*')
		return (1);
	return (0);
}

int		ft_isparam(int a, int b)
{
	if (a == '*' && b == 1)
		return (9);
	else if (a == 'd')
		return (0);
	else if (a == 'c')
		return (1);
	else if (a == 's')
		return (2);
	else if (a == 'p')
		return (3);
	else if (a == 'i')
		return (4);
	else if (a == 'u')
		return (5);
	else if (a == 'x')
		return (6);
	else if (a == 'X')
		return (7);
	else if (a == '%')
		return (8);
	return (-1);
}

char	*ft_trimarg(char *arg)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_strlen(arg) + 1));
	g_j = 0;
	i = 0;
	while (arg[i])
	{
		while (arg[i] != '%' && arg[i])
			str[g_j++] = arg[i++];
		if (arg[i] == '\0')
			break ;
		str[g_j++] = arg[i++];
		while (ft_isflag(arg[i]))
		{
			if (arg[i] == '*')
				str[g_j++] = arg[i++];
			else
				i++;
		}
		if (ft_isparam(arg[i], 0) >= 0)
			str[g_j++] = arg[i++];
	}
	str[g_j] = '\0';
	return (str);
}
