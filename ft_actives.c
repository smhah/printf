/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_activeS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:42:16 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 11:42:18 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_actives(char *flags, char **tab, int i, char **strnum)
{
	char	*add;
	int		indice;
	int		len;

	indice = -1;
	len = atoi((*strnum)) - ft_strlen(*tab);
	if (len < 0 && flags[i] != '.')
		return (ft_free1(strnum));
	add = malloc(sizeof(char) * len);
	if (ft_checkfirst(flags, i))
		indice = 1;
	if (indice > 0 && flags[i] == '-' &&
		(flags[i - 1] != '-' || flags[i + 1] != '-'))
		ft_flagmoins(tab, &add, len);
	else if (flags[i] == '.' && flags[i + 1] != '-')
	{
		*tab = ft_trim(tab, strnum);
		free(add);
	}
	else if (ft_isdigit(flags[i]))
		ft_flagdigits(tab, &add, len);
	return (ft_free1(strnum));
}

int		ft_cnd2s(int a, int b, int i, char *flags)
{
	if (ft_isflag2(a))
	{
		if (a == '-')
		{
			if (ft_checkfirst(flags, i))
				return (1);
			return (-2);
		}
		return (1);
	}
	else if ((i == 0 && ft_isdigit(b)))
		return (1);
	return (0);
}

void	ft_toactives(char **tab, char **flags, char **str, int i)
{
	if ((*str)[0])
		*str = ft_verse(str);
	ft_actives(*flags, &(*tab), i, str);
}

int		ft_activeflags(char **flags, char **tab)
{
	int		i;
	int		j;
	char	*str;

	str = NULL;
	if (*flags && **flags != '\0')
	{
		i = ft_strlen(*flags);
		j = 0;
		while (--i >= 0)
		{
			if (str == NULL && (j = 0) > -1)
				str = malloc(ft_strlen(*flags) + 1);
			if (ft_isdigit((*flags)[i]))
				str[j++] = (*flags)[i];
			if (str && ft_cnd2s((*flags)[i], str[j - 1], i, &(*flags)[0]) > 0 &&
				(str[j] = '\0') == '\0')
				ft_toactives(tab, flags, &str, i);
			if (str && ft_cnd2s((*flags)[i], str[j - 1], i, &(*flags)[0]) < 0)
				ft_free1(&str);
		}
	}
	ft_puts(*tab);
	return (ft_strlen(*tab));
}
