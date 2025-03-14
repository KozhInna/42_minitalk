/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:59:18 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/14 15:37:43 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

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


int main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	int s_pid;
	int i;

	s_pid = ft_atoi(argv[1]);
	printf("s_pid received - %d", s_pid);

	i = 8;
	while (i-- > 0)
	{
		if ((argv[2][0] >> i) & 1)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		usleep(100);

	}
}


