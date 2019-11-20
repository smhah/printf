/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:59:28 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 11:59:47 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_trim(char **tab, char **strnum)
{
	char	*str;
	int		j;
	int		i;

	i = 0;
	j = ft_atoi((const char *)*strnum);
	str = malloc(j);
	while (j)
	{
		str[i] = (*tab)[i];
		i++;
		j--;
	}
	str[i] = '\0';
	free(*tab);
	tab = &str;
	return (*tab);
}

void	ft_flagmoins(char **tab, char **add, int len)
{
	*add = ft_memset(*add, ' ', len);
	(*add)[len] = '\0';
	*tab = ft_tabjoin(tab, add);
}

void	ft_flagdigits(char **tab, char **add, int len)
{
	*add = ft_memset(*add, ' ', len);
	(*add)[len] = '\0';
	*tab = ft_tabjoin(add, tab);
}

void	freeall(char **tab, char **flags, char **str, char **indices)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	i = 0;
	while (flags[i])
		free(flags[i++]);
	free(flags);
	free(*str);
	free(*indices);
}
