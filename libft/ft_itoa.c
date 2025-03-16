/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:56:25 by ikozhina          #+#    #+#             */
/*   Updated: 2024/11/14 13:38:27 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_count_len(int n);

char	*ft_itoa(int n)
{
	long	d;
	char	*res;
	size_t	count;

	d = (long)n;
	if (d < 0)
		d = -d;
	count = ft_count_len(n);
	res = malloc(sizeof(char) * (count + 1));
	if (res == NULL)
		return (NULL);
	res[count] = '\0';
	while (count > 0)
	{
		count--;
		if (count == 0 && n < 0)
			res[count] = '-';
		else
			res[count] = (d % 10) + 48;
		d = d / 10;
	}
	return (res);
}

static size_t	ft_count_len(int n)
{
	long	d;
	size_t	count;

	count = 0;
	d = (long)n;
	if (d <= 0)
	{
		count++;
		d = -d;
	}
	while (d != 0)
	{
		count++;
		d = d / 10;
	}
	return (count);
}
