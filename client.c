/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:59:58 by nosilves          #+#    #+#             */
/*   Updated: 2023/08/31 22:31:50 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	int_binari(char c, pid_t cp)
{
	int	bin;

	bin = 0;
	while (bin < 32)
	{
		if ((c & (2147483648 >> bin)) == 0)
			kill (cp, SIG_0);
		else
			kill (cp, SIG_1);
		bin++;
		usleep(100);
	}
}

void	char_binari(char c, pid_t cp)
{
	int	bin;

	bin = 0;
	while (bin < 8)
	{
		if ((c & (128 >> bin)) == 0)
			kill (cp, SIG_0);
		else
			kill (cp, SIG_1);
		bin++;
		usleep(100);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	res;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = n * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	res = res * n;
	return (res);
}

void	sig_handler(int signum)
{
	if (signum == SIG_0)
	{
		ft_printf("\ngot it 👌\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	pid_t	cp;
	int		i;

	i = 0;
	signal(SIG_0, sig_handler);
	signal(SIG_1, sig_handler);
	if (argc != 3)
	{
		ft_printf("ERROOOOOOOR");
		return (0);
	}
	cp = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
		i++;
	int_binari(i, cp);
	pause();
	i = 0;
	while (argv[2][i])
	{
		char_binari(argv[2][i], cp);
		i++;
	}
	char_binari('\0', cp);
	pause();
}
