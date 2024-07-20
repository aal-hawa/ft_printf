/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:47:14 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/20 20:45:40 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list arg;
	int i;

	i = 0;
	va_start(arg, format);
	while (*format)
	{
		if(*format == '%')
		{
			format++;
			if (*format == 'c')
				i+= ft_putchr(va_arg(arg, int));
			else if(*format == 's')
				i+= ft_putstr(va_arg(arg, char *));
			else if(*format == 'p')
				i+= ft_putpointer(va_arg(arg, void *));
			else if(*format == 'd' || *format == 'i')
				i+= ft_putnbr(va_arg(arg, int));
			else if(*format == 'u')
				i+= ft_put_unsigned(va_arg(arg, unsigned int)); //unsigned
			else if(*format == 'x')
				i+= ft_puthexlowercase(va_arg(arg,  unsigned int)); //unsigned
			else if(*format == 'X')
				i+= ft_puthexuppercase(va_arg(arg,  unsigned int)); //unsigned
			else if(*format == '%')
				i+= ft_putchr('%');
		}
		else
			i+= ft_putchr(*format);
		format++;
	}
	va_end(arg);
	return (i);
}



