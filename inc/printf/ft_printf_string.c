/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:49:30 by nosilves          #+#    #+#             */
/*   Updated: 2023/06/14 21:06:56 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printstring(char *s)
{
	int	i;
	int	charses;
	int	res;

	i = 0;
	charses = 0;
	if (s == NULL)
	{
		res = write(1, "(null)", 6);
		return (res);
	}
	while (s[i] != '\0')
	{
		res = write (1, &s[i], 1);
		if (res == -1)
			return (-1);
		charses++;
		i++;
	}
	return (charses);
}
