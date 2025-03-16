/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 23:06:17 by ikozhina          #+#    #+#             */
/*   Updated: 2024/11/15 14:57:49 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*p_src;
	unsigned char		*p_dest;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	p_src = (unsigned char *) src;
	p_dest = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}
