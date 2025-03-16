/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:34:57 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/16 22:19:22 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../libft.h"

int	ft_putnbr(int n)
{
	char	c;
	long	i;
	int		count;

	i = n;
	count = 0;
	if (i < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		i = -i;
	}
	if (i >= 10)
		count += ft_putnbr(i / 10);
	i = i % 10;
	c = i + '0';
	if (ft_putchar(c) == -1)
		return (-1);
	count++;
	return (count);
}
