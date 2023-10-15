/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:00:32 by nosilves          #+#    #+#             */
/*   Updated: 2023/08/31 22:52:41 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_missatge = NULL;

void	numero_array_de_ints(int bit, siginfo_t *info)
{
	static int	i = 0;
	static int	num_bits = 0;

	if (bit == 1)
		i = i | (2147483648 >> num_bits);
	if (++num_bits == 32)
	{
		g_missatge = malloc (sizeof(char) * i + 1);
		if (!g_missatge)
		{
			ft_printf ("malloc error");
			exit(0);
		}
		sleep(1);
		kill(info->si_pid, SIG_1);
		i = 0;
		num_bits = 0;
	}
}

void	numero_array_de_char(int bit, siginfo_t *info)
{
	static char	c = 0;
	static int	num_bits = 0;
	static int	len = 0;

	if (bit == 1)
		c = c | (128 >> num_bits);
	if (++num_bits == 8)
	{
		g_missatge[len] = c;
		len++;
		if (c == '\0')
		{
			kill(info->si_pid, SIG_0);
			ft_printf ("%s\n", g_missatge);
			len = 0;
			free (g_missatge);
			g_missatge = NULL;
		}
		c = '\0';
		num_bits = 0;
	}
}

void	catcher0(int signum, siginfo_t *info, void *vp)
{
	(void)signum;
	(void)vp;
	if (g_missatge == NULL)
		numero_array_de_ints(0, info);
	else
		numero_array_de_char(0, info);
}

void	catcher1(int signum, siginfo_t *info, void *vp)
{
	(void)signum;
	(void)vp;
	if (g_missatge == NULL)
		numero_array_de_ints(1, info);
	else
		numero_array_de_char(1, info);
}

int	main(void)
{
	struct sigaction	sa0;
	struct sigaction	sa1;
	pid_t				cp;

	cp = getpid();
	ft_printf("pid: %d \n", cp);
	sa0.sa_flags = SA_SIGINFO;
	sa0.sa_sigaction = catcher0;
	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = catcher1;
	sigaction(SIG_0, &sa0, 0);
	sigaction(SIG_1, &sa1, 0);
	while (1)
		pause();
}
