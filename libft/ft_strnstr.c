/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:22:16 by ikozhina          #+#    #+#             */
/*   Updated: 2024/11/14 13:49:23 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (j < len && haystack[j])
	{
		if (needle[i] != haystack[j])
			j++;
		if (needle[i++] == haystack[j++])
		{
			if (needle[i] == '\0')
				return ((char *)&(haystack[j]) - i);
		}
		else
			i = 0;
	}
	return (NULL);
}
