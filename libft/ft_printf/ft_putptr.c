/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:48:01 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/16 22:19:28 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../libft.h"

int	ft_putptr(void *ptr, int base, char l)
{
	int	count;
	int	res;

	count = 0;
	if (!ptr)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	count += 2;
	res = ft_putnbr_unsigned((uintptr_t)ptr, base, l);
	if (res == -1)
		return (-1);
	count += res;
	return (count);
}
