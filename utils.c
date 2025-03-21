/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:31:23 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/19 11:31:36 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(pid_t pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_printf("\nFailed to send %d to PID %d\n", signal, pid);
		exit(1);
	}
}
