/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:45:13 by ikozhina          #+#    #+#             */
/*   Updated: 2024/11/15 10:40:12 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	set_index(char c, char const *set);
static char	*copy_string(char const *index_s, char const *index_e);

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*copy_s1;
	const char	*index_s;
	const char	*index_e;
	size_t		len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	index_s = s1;
	while (*index_s && set_index(*index_s, set))
		index_s++;
	index_e = s1 + len - 1;
	while (index_e >= index_s && set_index(*index_e, set))
		index_e--;
	if (index_s > index_e)
		return (ft_strdup(""));
	copy_s1 = copy_string(index_s, index_e);
	return (copy_s1);
}

static int	set_index(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*copy_string(char const *index_s, char const *index_e)
{
	char	*copy_str;
	size_t	i;

	i = 0;
	copy_str = malloc(sizeof(char) * (index_e - index_s + 2));
	if (copy_str == NULL)
		return (NULL);
	while (index_s <= index_e)
	{
		copy_str[i] = *index_s;
		i++;
		index_s++;
	}
	copy_str[i] = '\0';
	return (copy_str);
}
