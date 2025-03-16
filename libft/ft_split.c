/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:09:17 by ikozhina          #+#    #+#             */
/*   Updated: 2024/11/19 12:30:55 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_calc_words(char const *str, char delimiter, size_t len);
static void	ft_mem_allocate(char **ar_str, char const *str, char delimiter);
static void	ft_copy_words(char **ar_str, char const *str, char delimiter);
static void	ft_free(char **ar_str, size_t x);

char	**ft_split(char const *str, char delimiter)
{
	char	**ar_str;
	char	*trimmed_str;
	char	str_del[2];
	size_t	len_arr;

	if (str == NULL)
		return (NULL);
	str_del[0] = delimiter;
	str_del[1] = '\0';
	trimmed_str = ft_strtrim(str, str_del);
	if (trimmed_str == NULL)
		return (NULL);
	len_arr = ft_calc_words(trimmed_str, delimiter, ft_strlen(trimmed_str));
	ar_str = malloc(sizeof(char *) * (len_arr + 1));
	if (ar_str == NULL)
	{
		free(trimmed_str);
		return (NULL);
	}
	ar_str[len_arr] = NULL;
	ft_mem_allocate(ar_str, trimmed_str, delimiter);
	ft_copy_words(ar_str, trimmed_str, delimiter);
	free(trimmed_str);
	return (ar_str);
}

static int	ft_calc_words(char const *str, char delimiter, size_t len)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (str[i] == delimiter)
		{
			i++;
			continue ;
		}
		while (str[i] != delimiter && str[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static void	ft_mem_allocate(char **ar_str, char const *str, char delimiter)
{
	size_t	i;
	size_t	x;
	size_t	count;

	i = 0;
	x = 0;
	while (str[i])
	{
		count = 0;
		while (str[i] != delimiter && str[i] != '\0')
		{
			count++;
			i++;
		}
		if (count != 0)
		{
			ar_str[x] = malloc(sizeof(char) * (count + 1));
			if (ar_str[x] == NULL)
				return (ft_free(ar_str, x));
			x++;
		}
		if (str[i] == delimiter)
			i++;
	}
}

static void	ft_free(char **ar_str, size_t x)
{
	size_t	i;

	i = 0;
	while (i < x)
	{
		free(ar_str[i]);
		i++;
	}
	free(ar_str);
}

static void	ft_copy_words(char **ar_str, char const *str, char delimiter)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	x = 0;
	while (str[i])
	{
		while (str[i] == delimiter && str[i] != '\0')
			i++;
		y = 0;
		while (str[i] != delimiter && str[i] != '\0')
		{
			ar_str[x][y] = str[i];
			y++;
			i++;
		}
		ar_str[x][y] = '\0';
		x++;
	}
}
