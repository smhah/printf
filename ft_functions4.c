/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:41:26 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 11:41:28 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putc(char c)
{
	write(1, &c, 1);
}

int		ft_putczero(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_puts(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putc(str[i++]);
}

void	ft_flagmoinc(char **add, char **tab, int len)
{
	*add = ft_memset(*add, ' ', len);
	(*add)[len] = '\0';
	ft_putc((*tab)[0]);
	ft_puts(*add);
}

void	ft_flagdigitc(char **tab, char **add, int len)
{
	*add = ft_memset(*add, ' ', len);
	(*add)[len] = '\0';
	ft_puts(*add);
	ft_putc((*tab)[0]);
}
