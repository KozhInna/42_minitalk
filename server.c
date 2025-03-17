/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:59:21 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/17 15:12:51 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	assemble_str(char c);

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;

	(void)context;
	(void)siginfo;
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = (c << 1) | 0;
	i++;
	if (i == 8)
	{
		assemble_str(c);
		// if (c == '\0')
		// 	write(1, "\n", 1);
		// else
		// write(1, &c, 1);
		i = 0;
		c = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

void	assemble_str(char c)
{
	static char		buffer[5000];
	static size_t	i = 0;

	buffer[i++] = c;
	if (c == '\0')
	{
		write(1, &buffer, i);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server pid - %d\n", getpid());
	while (1)
		pause();
	return (0);
}
