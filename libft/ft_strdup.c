/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:07:33 by ikozhina          #+#    #+#             */
/*   Updated: 2024/11/15 14:58:55 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr_s;
	size_t	len;

	len = ft_strlen(s);
	ptr_s = malloc(len + 1);
	if (ptr_s == NULL)
		return (NULL);
	ft_memcpy(ptr_s, s, len);
	ptr_s[len] = '\0';
	return (ptr_s);
}
