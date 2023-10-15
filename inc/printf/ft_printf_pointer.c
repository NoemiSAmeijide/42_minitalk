/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:51:47 by nosilves          #+#    #+#             */
/*   Updated: 2023/06/15 21:54:22 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printnbrpointers(unsigned long l, char *base)
{
	int			charses;
	int			res;

	charses = 0;
	if (l >= 16)
	{
		charses = ft_printnbrpointers(l / 16, base);
		if (charses == -1)
			return (-1);
		res = write (1, &base[l % 16], 1);
		if (res == -1)
			return (-1);
		charses += res;
	}
	else
	{
		res = write (1, &base[l], 1);
		if (res == -1 || charses == -1)
			return (-1);
		charses += res;
	}
	return (charses);
}

int	ft_printpointer(unsigned long p, char *base)
{
	int	charses;
	int	res;

	charses = write (1, "0x", 2);
	if (charses == -1)
		return (-1);
	res = ft_printnbrpointers(p, base);
	if (res == -1)
		return (-1);
	charses += res;
	return (charses);
}
