/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:22:35 by smhah             #+#    #+#             */
/*   Updated: 2019/10/21 17:56:41 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(unsigned int n, int fd)
{
	if (n <= 9)
		ft_putchar_fd(n + 48, fd);
	else
	{
		putnbr(n / 10, fd);
		putnbr(n % 10, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		putnbr(n * -1, fd);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + 48, fd);
		else
			putnbr(n, fd);
	}
}
