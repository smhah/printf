/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 09:53:00 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 09:53:02 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_g;
extern int g_j;
extern int g_i;
extern int g_k;

void	ft_valist(va_list n, char *indices, char **etoiles, char **tab)
{
	while (indices[g_i])
	{
		if (indices[g_i] == '9')
			etoiles[g_k++] = ft_itoa(va_arg(n, int));
		else if (indices[g_i] == '0' || indices[g_i] == '4')
			tab[g_j++] = ft_itoa(va_arg(n, int));
		else if (indices[g_i] == '1')
			tab[g_j++] = ft_char(va_arg(n, int));
		else if (indices[g_i] == '2')
			tab[g_j++] = ft_str(va_arg(n, char *));
		else if (indices[g_i] == '3')
			ft_freeadresse(n, &tab[g_j++]);
		else if (indices[g_i] == '5')
			tab[g_j++] = ft_untoa(va_arg(n, unsigned int));
		else if (indices[g_i] == '6')
			tab[g_j++] = ft_printhexa(va_arg(n, unsigned long long));
		else if (indices[g_i] == '7')
			tab[g_j++] =
				ft_toper(ft_printhexa(va_arg(n, unsigned long long)));
		else if (indices[g_i] == '8')
			tab[g_j++] = ft_strdup("%");
		g_i++;
	}
	tab[g_j] = NULL;
	etoiles[g_k] = NULL;
}

char	*ft_deletoiles(char **str)
{
	char	*newstr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	newstr = malloc(ft_strlen(*str) + 1);
	while ((*str)[i])
	{
		while ((*str)[i] && (*str)[i] != '%')
			newstr[j++] = (*str)[i++];
		newstr[j++] = (*str)[i];
		if ((*str)[i++])
		{
			while ((*str)[i] && (ft_isparam((*str)[i], 0)) < 0)
				i++;
			if ((*str)[i] == '%')
				newstr[j++] = (*str)[i++];
		}
	}
	newstr[j] = '\0';
	free(*str);
	return (newstr);
}

int		ft_checkindices1(char *indices, int i)
{
	if (indices[i] == '0' || indices[i] == '5' ||
		indices[i] == '6' || indices[i] == '4' ||
			indices[i] == '7' || indices[i] == '3')
		return (1);
	return (0);
}

int		ft_wichactive(char **flags, char **tab, char *indices, char **str)
{
	int		s;
	char	*str2;

	str2 = NULL;
	s = 0;
	while (indices[g_i])
	{
		while ((g_g == 0) && (*str)[g_k] != '%' &&
			(*str)[g_k] && ((s = s + 1) >= 0))
			ft_putc((*str)[g_k++]);
		if (ft_checkindices1(indices, g_i) && (g_j = g_j + 1) >= 0)
			s = ft_activeflag(&flags[g_j], &tab[g_j], &str2) + s;
		else if ((indices[g_i] == '2') && (g_j = g_j + 1) >= 0)
			s = ft_activeflags(&flags[g_j], &tab[g_j]) + s;
		else if (indices[g_i] == '1' && (g_j = g_j + 1) >= 0)
			s = ft_activeflagc(&flags[g_j], &tab[g_j], &str2) + s;
		else if (indices[g_i] == '8' && (g_j = g_j + 1) >= 0)
			s = ft_activeflagpercent(&flags[g_j], &tab[g_j]) + s;
		if ((*str)[g_k + 2] != '\0' && g_g == 0)
			g_k = g_k + 2;
		g_g = (indices[g_i++] == '9' ? 1 : 0);
	}
	while ((*str)[g_k] != '%' && (*str)[g_k] && (s = s + 1) >= 0)
		ft_putc((*str)[g_k++]);
	return (s);
}

int		ft_subprintf(char *indices, char **flags, va_list n, char **str)
{
	char	**tab;
	int		count;
	char	**etoiles;

	count = ft_count(*str);
	etoiles = (char **)malloc(sizeof(char *) * (ft_countetoiles(*str) + 1));
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	g_i = 0;
	g_k = 0;
	g_j = 0;
	ft_valist(n, indices, etoiles, tab);
	ft_modify(flags, etoiles);
	count = 0;
	if (ft_strchr(*str, '*'))
		*str = ft_deletoiles(str);
	g_g = 0;
	g_i = 0;
	g_j = -1;
	g_k = 0;
	count = ft_wichactive(flags, tab, indices, str);
	free(etoiles);
	freeall(tab, flags, str, &indices);
	return (count);
}
