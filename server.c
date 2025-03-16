/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:59:21 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/16 22:35:38 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void handle_sig(int sig)
{
	static int i = 0;
	static unsigned char c = 0;

	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = (c << 1) | 0;
	i++;
	if (i == 8)
	{
		printf("%c", c);
		fflush(stdout);
		i = 0;
		c = 0;
	}
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	d;
	unsigned char	*ptr_s;
	size_t			i;

	ptr_s = (unsigned char *) s;
	d = (unsigned char) c;
	i = 0;
	while (i < n)
		ptr_s[i++] = d;
	return (s);
}

int main(void)
{
	struct sigaction sa;
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &handle_sig;


	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server pid - %d\n", getpid());

	while (1)
		pause();
	return (0);
}




