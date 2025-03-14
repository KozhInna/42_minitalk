/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:59:18 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/14 22:56:25 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(res * sign));
}

void send_char(int pid, char c)
{
	int i;

	i = 8;
	while (i-- > 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
	}
}

int main(int argc, char **argv)
{
	int s_pid;
	size_t j;
	size_t len_str;
	
	if (argc != 3 || argv[2] == NULL || argv[2][0] == '\0')
		return (1);

	s_pid = ft_atoi(argv[1]);
	len_str = ft_strlen(argv[2]);
	printf("s_pid received - %d", s_pid);
	j = 0;
	while (j < len_str)
	{
		send_char(s_pid, argv[2][j]);
		j++;
	}
	send_char(s_pid, '\n');
	return (0);
}
		

