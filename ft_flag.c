/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:27:01 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 12:30:02 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_flag(char *arg, char *str)
{
	int		count;
	int		i;
	char	**tab;
	int		save;
	int		a;

	count = ft_count(str);
	tab = malloc(sizeof(char *) * (count + 1));
	a = 0;
	i = 0;
	while (arg[i] && (save = 0) >= 0)
	{
		if (arg[i++] == '%' && (save = i) >= 0)
		{
			while ((arg[i] && (ft_isflag(arg[i]) || arg[i] == '*')))
				i++;
			if ((arg[i] && (ft_isparam(arg[i], 0) >= 0)))
			{
				tab[a++] = ft_substr(arg, save, i - save);
				i++;
			}
		}
	}
	tab[a] = NULL;
	return (tab);
}
