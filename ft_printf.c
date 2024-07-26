/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:47:14 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/26 17:06:28 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list arg, const char *format)
{
	int	i;

	i = 0;
	format++;
	if (*format == 'c')
		i = ft_putchr(va_arg(arg, int));
	else if (*format == 's')
		i = ft_putstr(va_arg(arg, char *));
	else if (*format == 'p')
		i = ft_putpointer(va_arg(arg, void *));
	else if (*format == 'd' || *format == 'i')
		i = ft_putnbr(va_arg(arg, int));
	else if (*format == 'u')
		i = ft_pt_un(va_arg(arg, unsigned int));
	else if (*format == 'x')
		i = ft_hxlwr(va_arg(arg, unsigned int));
	else if (*format == 'X')
		i = ft_hxupr(va_arg(arg, unsigned int));
	else if (*format == '%')
		i = ft_putchr('%');
	return (i);
}

int	ft_while_format(va_list arg, const char *format)
{
	int		i;
	int		i_all;

	i = 0;
	i_all = 0;
	while (*format)
	{
		if (*format == '%')
		{
			i = ft_format(arg, format);
			if (i == -1)
				return (-1);
			i_all += i;
			format++;
		}
		else
		{
			i = ft_putchr(*format);
			if (i == -1)
				return (-1);
			i_all += i;
		}
		format++;
	}
	return (i_all);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i_all;

	if (!format)
		return (-1);
	i_all = 0;
	va_start(arg, format);
	i_all = ft_while_format(arg, format);
	va_end (arg);
	return (i_all);
}
