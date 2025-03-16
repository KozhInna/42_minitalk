/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:38:41 by ikozhina          #+#    #+#             */
/*   Updated: 2024/11/15 14:45:56 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
