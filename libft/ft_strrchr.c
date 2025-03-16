/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:35:38 by ikozhina          #+#    #+#             */
/*   Updated: 2024/11/19 13:47:47 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pnt_s;

	pnt_s = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			pnt_s = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (pnt_s);
}
