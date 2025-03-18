/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:59:18 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/18 13:47:38 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	send_char(int pid, char c)
{
	int		i;

	i = 8;
	while (i-- > 0)
	{
		if (kill(pid, 0) == -1)
		{
			write(1, "Server is not running\n", 22);
			exit(1);
		}
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack_received)
			pause();
		g_ack_received = 0;
	}
}

void	receive_ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

int	pid_check(char *pid_str)
{
	int	i;
	int	pid;

	i = 0;
	while (pid_str[i])
	{
		if (!ft_isdigit(pid_str[i++]))
			exit(1);
	}
	pid = ft_atoi(pid_str);
	if (pid <= 0 || kill(pid, 0) != 0)
		exit(1);
	return (pid);
}

int	main(int argc, char **argv)
{
	int					server_pid;
	size_t				j;
	size_t				len_str;
	struct sigaction	sa;

	if (argc != 3)
		return (ft_printf("\nProgram expects 2 parameters\n"), 1);
	if (argv[2] == NULL || argv[2][0] == '\0')
		return (ft_printf("\nNothing to send\n"), 1);
	j = 0;
	server_pid = pid_check(argv[1]);
	len_str = ft_strlen(argv[2]);
	ft_memset(&sa, 0, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &receive_ack_handler;
	sigaction(SIGUSR1, &sa, NULL);
	while (j <= len_str)
		send_char(server_pid, argv[2][j++]);
	return (0);
}
