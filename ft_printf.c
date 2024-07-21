/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:47:14 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/21 18:00:40 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int flags_bonus(const char *format, char flag)
{
	long count_len;

	count_len = 0;
	if (flag != 'L')
		format++;
	if (flag == '-' || flag == '0'|| flag == '.'|| flag == 'L')
	{
		while (*format >= '0' && *format <= '9')
		{
			count_len *= 10;
			count_len += *format - '0';
			format++;
		}
	}
	return ((int) count_len);
}

int	ft_printf(const char *format, ...)
{
	va_list arg;
	int i;
	int	count_len;
	char flag;
	int isflag_char;

	isflag_char = 0;
	flag = '\0';
	count_len = 0;
	i = 0;
	va_start(arg, format);
	while (*format)
	{
		if(*format == '%' || isflag_char)
		{
			if(*format == '%')
				format++;
			if (*format == 'c')
				i+= ft_putchr_format(va_arg(arg, int), count_len, flag);
			else if(*format == 's')
				i+= ft_putstr(va_arg(arg, char *), count_len, flag);
			else if(*format == 'p')
				i+= ft_putpointer(va_arg(arg, void *));
			else if(*format == 'd' || *format == 'i')
				i+= ft_putnbr(va_arg(arg, int), count_len, flag);
			else if(*format == 'u')
				i+= ft_put_unsigned(va_arg(arg, unsigned int)); //unsigned
			else if(*format == 'x')
				i+= ft_puthexlowercase(va_arg(arg,  unsigned int), flag); //unsigned
			else if(*format == 'X')
				i+= ft_puthexuppercase(va_arg(arg,  unsigned int), flag); //unsigned
			else if(*format == '%')
				i+= ft_putchr('%');
			else if (*format == '-' || *format == '0' || *format == '.' ||
					*format == '#' || *format == ' ' || *format == '+')
			{
				flag = *format;
				isflag_char = 1;
				if (*format == '-' || *format == '0' || *format == '.')
					count_len = flags_bonus(&(*format), *format);
			}
			else if (*format >= '1' && *format <= '9')
			{
				flag = 'L';
				isflag_char = 1;
				count_len = flags_bonus(&(*format), flag);
			}
			if (isflag_char == 1)
				isflag_char++;
			else if(isflag_char == 2)
			{
				isflag_char = 0;
				count_len = 0;
				flag = '\0';
			}
		}
		else
			i+= ft_putchr(*format);
		format++;
		if (count_len)	
		{
			while (*format >= '0' && *format <= '9')
				format++;
		}
	}
	va_end(arg);
	return (i);
}



