/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:41:16 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 12:13:34 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagmoin(char **tab, char **add, int indice, int len)
{
	*add = ft_memset(*add, ' ', len);
	(*add)[len] = '\0';
	*tab = ft_tabjoin(tab, add);
	if (indice == 2)
		*tab = ft_tabjoin2("-", tab);
}

void	ft_flagpoint(char **tab, char **add, int indice, int len)
{
	*add = ft_memset(*add, '0', len);
	(*add)[len] = '\0';
	*tab = ft_tabjoin(add, tab);
	if (indice == 2)
		*tab = ft_tabjoin2("-", tab);
}

void	ft_flagdigit(char **tab, char **add, int indice, int len)
{
	*add = ft_memset(*add, ' ', len);
	(*add)[len] = '\0';
	if (indice == 2)
		*tab = ft_tabjoin2("-", tab);
	*tab = ft_tabjoin(add, tab);
}

void	ft_free1(char **strnum)
{
	free((*strnum));
	*strnum = NULL;
}

int		ft_checknegative(char **tab, char *flags, int i, int *len)
{
	if (flags[i] == '.')
		*len = *len + 1;
	ft_delfirst(tab);
	return (2);
}
