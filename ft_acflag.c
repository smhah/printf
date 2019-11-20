/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:35:11 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 14:35:13 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_active(char *flags, char **tab, int i, char **strnum)
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
	if (atoi(*tab) < 0)
		indice = ft_checknegative(tab, flags, i, &len);
	if (indice > 0 && flags[i] == '-' &&
			(flags[i - 1] != '-' || flags[i + 1] != '-'))
		ft_flagmoin(tab, &add, indice, len);
	else if (flags[i] == '0' || flags[i] == '.')
		ft_flagpoint(tab, &add, indice, len);
	else if (ft_isdigit(flags[i]))
		ft_flagdigit(tab, &add, indice, len);
	else if (indice == 2)
		*tab = ft_tabjoin2("-", tab);
	return (ft_free1(strnum));
}

char	*ft_verse(char **str)
{
	char	*rev;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(*str);
	rev = malloc(ft_strlen(*str) + 1);
	while (--i >= 0)
		rev[j++] = (*str)[i];
	rev[j] = '\0';
	free(*str);
	str = NULL;
	return (rev);
}

void	ft_toactive(char **tab, char **flags, char **str, int i)
{
	if ((*str)[0])
		*str = ft_verse(str);
	ft_active(*flags, &(*tab), i, str);
}

int		ft_free12(char **str)
{
	free(*str);
	*str = NULL;
	return (1);
}

int		ft_activeflag(char **flags, char **tab, char **str)
{
	int		i;
	int		j;

	if (*flags && **flags != '\0')
	{
		i = ft_strlen(*flags);
		j = 0;
		while (--i >= 0)
		{
			if (*str == NULL && (j = 0) >= 0)
				*str = malloc(ft_strlen(*flags) + 1);
			if (ft_isdigit((*flags)[i]))
				(*str)[j++] = (*flags)[i];
			if (ft_cnd2((*flags)[i], (*str)[j - 1], i, *flags) == -2
				&& ft_atoi(*tab) == 0)
				i -= ft_free12(str);
			if (*str && ft_cnd2((*flags)[i], (*str)[j - 1], i, *flags) > 0 &&
					((*str)[j] = '\0') == '\0')
				ft_toactive(tab, flags, str, i);
			if (*str && ft_cnd2((*flags)[i],
				(*str)[j - 1], i, &(*flags)[0]) < 0)
				ft_free1(str);
		}
	}
	return (ft_putscount(*tab));
}
