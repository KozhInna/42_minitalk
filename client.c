/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:59:18 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/17 13:44:35 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	i;

	i = 8;
	while (i-- > 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
	}
}

void	receive_ack_handler(int sig)
{
	(void)sig;
}

int	main(int argc, char **argv)
{
	int		s_pid;
	size_t	j;
	size_t	len_str;
	struct sigaction sa;

	if (argc != 3 || argv[2] == NULL || argv[2][0] == '\0')
		return (1);
	j = 0;
	s_pid = ft_atoi(argv[1]);
	len_str = ft_strlen(argv[2]);
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &receive_ack_handler;
	sigaction(SIGUSR1, &sa, NULL);

	while (j <= len_str)
		send_char(s_pid, argv[2][j++]);
	return (0);
}
