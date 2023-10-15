/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:39:35 by nosilves          #+#    #+#             */
/*   Updated: 2023/08/31 22:52:02 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf(char const *s, ...);
int	ft_printchar(int c);
int	ft_printstring(char *s);
int	ft_printpointer(unsigned long p, char *base);
int	ft_printnbr(int n);
int	ft_printunsigned(unsigned int num);
int	ft_printhexa(unsigned int h, char *base);

#endif
