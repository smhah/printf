/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:55:45 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 14:55:46 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strcpy(char *str1, char *str2, int j)
{
	int i;
	int a;

	a = 0;
	i = ft_strlen(str2) + j;
	while (str2[a])
	{
		str1[a] = str2[a];
		a++;
	}
	return (i);
}

char	*ft_str(char *s)
{
	if (s == NULL)
		return (ft_strdup("(null)"));
	s = ft_strdup(s);
	return (s);
}

char	*ft_char(char s)
{
	char *str;

	str = malloc(1);
	if (s == '\0')
	{
		*str = '\0';
		return (str);
	}
	str[1] = '\0';
	str[0] = s;
	return (str);
}

char	*ft_toper(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

void	ft_freeadresse(va_list n, char **tab)
{
	char *str;

	str = ft_printadresse(va_arg(n, unsigned long long));
	*tab = ft_strdup("0x");
	*tab = ft_tabjoin(tab, &str);
}
