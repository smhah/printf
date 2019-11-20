/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_untoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:47:09 by smhah             #+#    #+#             */
/*   Updated: 2019/11/20 13:47:12 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_unsigneditoa(char *s, unsigned long long n, int *p)
{
	if (n <= 9)
		s[*p] = n + 48;
	else
	{
		ft_unsigneditoa(s, n / 10, p);
		*p = *p + 1;
		ft_unsigneditoa(s, n % 10, p);
	}
	return (s);
}

static char	*condition2(unsigned long long n, int len, int *p)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n <= 9)
		str[*p] = n + 48;
	else
		ft_unsigneditoa(str, n, p);
	str[*p + 1] = '\0';
	return (str);
}

static char	*condition3(int len)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (len + 2));
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_untoa(unsigned int n)
{
	char	*str;
	int		b;
	int		len;
	int		*p;
	int		i;

	len = 0;
	b = n;
	while (b != 0)
	{
		b = b / 10;
		len++;
	}
	i = 0;
	p = &i;
	if (n > 0)
		str = condition2(n, len, p);
	else
		return (condition3(len));
	return (str);
}
