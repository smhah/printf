/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_activepercent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:01:17 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 12:11:46 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_activepercent(char *flags, char **tab, int i, char **strnum)
{
	char	*add;
	int		indice;
	int		len;

	indice = -1;
	if (ft_atoi(&flags[i]) == 0 && ft_atoi(*tab) == 0 && ft_isnum(tab))
		(*tab)[0] = '\0';
	len = atoi((*strnum)) - ft_strlen(*tab);
	if (len < 0)
		return (ft_free1(strnum));
	add = malloc(sizeof(char) * len);
	if (ft_checkfirst(flags, i))
		indice = 1;
	if (indice > 0 && flags[i] == '-' &&
			(flags[i - 1] != '-' || flags[i + 1] != '-'))
		ft_flagmoin(tab, &add, indice, len);
	else if (flags[i] == '0')
		ft_flagpoint(tab, &add, indice, len);
	else if (ft_isdigit(flags[i]))
		ft_flagdigit(tab, &add, indice, len);
	else
		free(add);
	return (ft_free1(strnum));
}

int		ft_putscount(char *s)
{
	int i;

	i = 0;
	while (s[i])
		ft_putc(s[i++]);
	return (i);
}

void	ft_toactivep(char **tab, char **flags, char **str, int i)
{
	if ((*str)[0])
		*str = ft_verse(str);
	ft_activepercent(*flags, &(*tab), i, str);
}

int		ft_activeflagpercent(char **flags, char **tab)
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
			if (str == NULL && (j = 0) >= 0)
				str = malloc(ft_strlen(*flags) + 1);
			if (ft_isdigit((*flags)[i]))
				str[j++] = (*flags)[i];
			if (str && ft_cnd2((*flags)[i], str[j - 1], i, *flags) > 0 &&
					(str[j] = '\0') == '\0')
				ft_toactivep(tab, flags, &str, i);
			if (str && ft_cnd2((*flags)[i], str[j - 1], i, &(*flags)[0]) < 0)
				ft_free1(&str);
		}
	}
	ft_puts(*tab);
	return (ft_strlen(*tab));
}
