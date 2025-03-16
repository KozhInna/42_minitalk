/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:02:52 by ikozhina          #+#    #+#             */
/*   Updated: 2025/03/16 22:19:08 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../libft.h"

static int	modify(va_list arg, char l);
static int	process_str(va_list arg, const char *str, int *size);

int	ft_printf(const char *str, ...)
{
	int		size;
	va_list	arg;

	if (!str)
		return (-1);
	size = 0;
	va_start(arg, str);
	if (process_str(arg, str, &size) == -1)
	{
		va_end(arg);
		return (-1);
	}
	va_end(arg);
	return (size);
}

static int	process_str(va_list arg, const char *str, int *size)
{
	int	res;

	res = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '\0')
				break ;
			else
				res = modify(arg, *str);
		}
		else
			res = ft_putchar(*str);
		if (res == -1)
			return (-1);
		*size += res;
		str++;
	}
	return (0);
}

static int	modify(va_list arg, char l)
{
	if (l == '%')
		return (ft_putchar(l));
	else if (l == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (l == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (l == 'd' || l == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (l == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int), 10, l));
	else if (l == 'X' || l == 'x')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int), 16, l));
	else if (l == 'p')
		return (ft_putptr(va_arg(arg, void *), 16, l));
	return (-1);
}
