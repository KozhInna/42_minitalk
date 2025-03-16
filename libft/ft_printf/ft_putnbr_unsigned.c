/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:18:41 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/16 22:19:19 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../libft.h"

int	ft_putnbr_unsigned(unsigned long n, int base, char l)
{
	int			count;
	char		c;
	const char	str[16] = "0123456789ABCDEF";

	count = 0;
	if (n >= (unsigned long)base)
		count += ft_putnbr_unsigned(n / base, base, l);
	n = n % base;
	c = str[n];
	if ((l == 'x' || l == 'p') && c >= 'A' && c <= 'F')
		c += 32;
	if (ft_putchar(c) == -1)
		return (-1);
	count++;
	return (count);
}
