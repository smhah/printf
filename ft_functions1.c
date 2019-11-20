/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:41:10 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 12:21:48 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkfirst(char *flags, int i)
{
	if (flags[i - 1] == '0' && i == 1)
		return (1);
	while (flags[i] == '-')
		i--;
	if (i == -1)
		return (1);
	return (0);
}

char	*ft_tabjoin(char **s1, char **s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*s;

	if (*s1 && *s2)
		i = ft_strlen(*s1);
	else
		return (0);
	j = ft_strlen(*s2);
	if (!(s = malloc(sizeof(char) * (i + j + 1))))
		return (0);
	i = 0;
	j = 0;
	while ((*s1)[i] != '\0')
	{
		s[i] = (*s1)[i];
		i++;
	}
	while ((*s2)[j] != '\0')
		s[i++] = (*s2)[j++];
	s[i] = '\0';
	free(*s1);
	free(*s2);
	return (s);
}

char	*ft_tabjoin2(char *s1, char **s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*s;

	if (s1 && *s2)
		i = ft_strlen(s1);
	else
		return (0);
	j = ft_strlen(*s2);
	if (!(s = malloc(sizeof(char) * (i + j + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	while ((*s2)[j] != '\0')
		s[i++] = (*s2)[j++];
	s[i] = '\0';
	free(*s2);
	return (s);
}

void	ft_delfirst(char **tab)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(ft_strlen(*tab));
	i = 0;
	j = 0;
	while ((*tab)[i++])
		str[j++] = (*tab)[i];
	str[j] = '\0';
	free(*tab);
	*tab = str;
}

int		ft_isnum(char **tab)
{
	int i;

	i = 0;
	while ((*tab)[i])
	{
		if (!ft_isdigit((*tab)[i]))
			return (0);
		i++;
	}
	return (1);
}
