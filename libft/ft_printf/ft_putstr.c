/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:03:48 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/16 22:19:32 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../libft.h"

int	ft_putstr(char *s)
{
	int	length;

	length = 0;
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[length])
	{
		if (ft_putchar(s[length]) == -1)
			return (-1);
		length ++;
	}
	return (length);
}
