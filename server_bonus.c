/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:59:21 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/19 12:23:39 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	handler(int sig, siginfo_t *siginfo, void *context);
static void	assemble_str(char c, pid_t client_pid);

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}

static void	assemble_str(char c, pid_t client_pid)
{
	static char		buffer[BUFFER_SIZE];
	static size_t	i = 0;

	buffer[i++] = c;
	if (c == '\0')
	{
		buffer[i - 1] = '\0';
		write(1, &buffer, i - 1);
		write(1, "\n", 1);
		send_signal(client_pid, SIGUSR2);
		i = 0;
	}
}

static void	handler(int sig, siginfo_t *siginfo, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;

	(void)context;
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = (c << 1) | 0;
	i++;
	if (i == 8)
	{
		assemble_str(c, siginfo->si_pid);
		i = 0;
		c = 0;
	}
	send_signal(siginfo->si_pid, SIGUSR1);
}
