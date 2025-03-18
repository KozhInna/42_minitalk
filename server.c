/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:59:21 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/18 13:25:49 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	assemble_str(char c)
{
	static char		buffer[BUFFER_SIZE];
	static size_t	i = 0;

	buffer[i++] = c;
	if (c == '\0')
	{
		buffer[i - 1] = '\0';
		write(1, &buffer, i - 1);
		write(1, "\n", 1);
		i = 0;
	}
}

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;

	(void)context;
	if (siginfo->si_pid <= 0)
	{
		write(1, "Error siginfo\n", 14);
		return ;
	}
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = (c << 1) | 0;
	i++;
	if (i == 8)
	{
		assemble_str(c);
		i = 0;
		c = 0;
	}
	if (kill(siginfo->si_pid, SIGUSR1) == -1)
		write(1, "Error kill\n", 11);
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
