/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_activeC.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 09:53:35 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 10:33:46 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_activec(char *flags, char **tab, int i, char **strnum)
{
	char	*add;
	int		ind;
	int		len;

	ind = 0;
	len = atoi((*strnum)) - 1;
	if (len < 0)
	{
		ft_free1(strnum);
		if (i == 0)
			ft_putc((*tab)[0]);
		return (1);
	}
	add = malloc(sizeof(char) * len);
	if (ft_checkfirst(flags, i))
		ind = 1;
	if (ind > 0 && flags[i] == '-' &&
		(flags[i - 1] != '-' || flags[i + 1] != '-'))
		ft_flagmoinc(&add, tab, len);
	else if (ft_isdigit(flags[i]))
		ft_flagdigitc(tab, &add, len);
	free(add);
	ft_free1(strnum);
	return (len + 1);
}

int		ft_toactivec(char **tab, char **flags, char **str, int i)
{
	if (flags[0][i] == '-' && flags[0][i + 1] == '-')
	{
		ft_free1(str);
		return (0);
	}
	else
	{
		if ((*str)[0])
			*str = ft_verse(str);
		return (ft_activec(*flags, &(*tab), i, str));
	}
	return (0);
}

int		ft_activeflagc(char **flags, char **tab, char **str)
{
	int len;
	int j;
	int i;

	len = 0;
	if (**flags != '\0' && (j = 0) >= 0)
	{
		i = ft_strlen(*flags);
		while (--i >= 0)
		{
			if (*str == NULL && (j = 0) >= 0)
				(*str) = malloc(ft_strlen((*flags)) + 1);
			if (ft_isdigit((*flags)[i]))
				(*str)[j++] = (*flags)[i];
			if ((*str) && ft_cnd2((*flags)[i], (*str)[j - 1], i, *flags)
				> 0 && ((*str)[j] = '\0') == '\0')
				if (!(len += ft_toactivec(tab, flags, str, i)))
					break ;
			if (ft_cnd2s((*flags)[i], (*str)[j - 1], i, &(*flags)[0]) < 0)
				ft_free1(str);
		}
	}
	else
		return (ft_putczero((*tab)[0]));
	return (len);
}
