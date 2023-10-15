/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:57:46 by nosilves          #+#    #+#             */
/*   Updated: 2023/06/15 21:50:33 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printhexa(unsigned int h, char *base)
{
	int			res;
	int			charses;

	charses = 0;
	res = 0;
	if (h >= 16)
	{
		res = ft_printhexa(h / 16, base);
		if (res == -1)
			return (-1);
		charses += res;
		res = write (1, &base[h % 16], 1);
		if (res == -1)
			return (-1);
		charses += res;
	}
	else
	{
		res = write (1, &base[h], 1);
		if (res == -1)
			return (-1);
		charses += res;
	}
	return (charses);
}
