/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:11:24 by nosilves          #+#    #+#             */
/*   Updated: 2023/06/15 21:55:17 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	what_to_print(char s, va_list arguments)
{
	int			charses;
	static char	*smin = "0123456789abcdef";	
	static char	*smax = "0123456789ABCDEF";

	charses = 0;
	if (s == '%')
		charses += write (1, "%", 1);
	else if (s == 'c')
		charses += ft_printchar(va_arg(arguments, int));
	else if (s == 's')
		charses += ft_printstring(va_arg(arguments, char *));
	else if (s == 'p')
		charses += ft_printpointer(va_arg(arguments, unsigned long), smin);
	else if (s == 'd' || s == 'i')
		charses += ft_printnbr(va_arg(arguments, int));
	else if (s == 'u')
		charses += ft_printunsigned(va_arg(arguments, unsigned int));
	else if (s == 'x')
		charses += ft_printhexa(va_arg(arguments, unsigned int), smin);
	else if (s == 'X')
		charses += ft_printhexa(va_arg(arguments, unsigned int), smax);
	return (charses);
}

int	ft_printf(char const *s, ...)
{
	int		i;
	int		charses;
	int		res;
	va_list	arguments;

	i = 0;
	charses = 0;
	va_start (arguments, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			res = what_to_print(s[i + 1], arguments);
			i = i + 2;
		}
		else
			res = (write (1, &s[i++], 1));
		if (res == -1)
			return (-1);
		charses = charses + res;
	}
	va_end (arguments);
	return (charses);
}
/*
#include <stdio.h>
int	main(void)
{
	char	s[] = "sdjkfsf";
	unsigned int	ui = 452423;
	int a;
	int b;

	//a = printf ("char: %c, string: %s, unsigned: %u, %%: %%, void: %p, 
	//decimal: %d, hexa: %x, HEXA: %X.\n", 'x', s, ui, &a, 0, 42, 42);
//	b = ft_printf ("char: %c, string: %s, unsigned: %u, %%: %%, void: %p,
//	decimal: %d, hexa: %x, HEXA: %X.\n", 'x', s, ui, &a, 0, 42, 42);
	
	a = printf ("%d%dd%d\n", 1, 2, -3);
	b = ft_printf ("%d%dd%d\n", 1, 2, -3);
	printf("Retorno original: %d\nretorno mia: %d\n", a, b);
}
*/
