/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:57:19 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/19 11:51:54 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define BUFFER_SIZE 2100000

# include "libft.h"
# include <signal.h>
# include <stdlib.h>

void	send_signal(pid_t pid, int signal);

#endif
