/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:55:41 by nosilves          #+#    #+#             */
/*   Updated: 2023/06/15 21:19:35 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printunsigned(unsigned int n)
{
	long	l;
	char	c;
	int		charses;
	int		res;

	charses = 0;
	res = 0;
	l = n;
	if (l / 10)
	{
		charses = ft_printunsigned(l / 10);
		if (charses == -1)
			return (-1);
	}
	c = l % 10 + '0';
	res = write (1, &c, 1);
	if (res == -1)
		return (-1);
	charses += res;
	return (charses);
}
