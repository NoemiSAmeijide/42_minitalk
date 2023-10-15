/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:54:18 by nosilves          #+#    #+#             */
/*   Updated: 2023/06/15 20:49:43 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printnbr_digits(long l)
{
	char	c;
	int		charses;
	int		tmp;

	charses = 0;
	tmp = 0;
	if (l / 10)
	{
		tmp = ft_printnbr(l / 10);
		if (tmp == -1)
			return (-1);
		charses += tmp;
	}
	if (charses == -1)
		return (-1);
	c = l % 10 + '0';
	tmp = write (1, &c, 1);
	if (tmp == -1)
		return (-1);
	return (charses + tmp);
}

int	ft_printnbr(int n)
{
	long	l;
	int		charses;
	int		tmp;

	charses = 0;
	tmp = 0;
	l = n;
	if (n < 0)
	{
		tmp = write (1, "-", 1);
		if (tmp == -1)
			return (-1);
		charses += tmp;
		l = -l;
	}
	tmp = ft_printnbr_digits(l);
	if (tmp == -1)
		return (-1);
	return (charses + tmp);
}
