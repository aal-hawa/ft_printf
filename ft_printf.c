/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:47:14 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/24 20:24:24 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_bonus(const char *format, char flag)
{
	long	count_len;

	count_len = 0;
	if (flag != 'L')
		format++;
	if (flag == '-' || flag == '0' || flag == '.' || flag == 'L')
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

char	check_after_bonus(char flag, int *i_cnt_isflag)
{
	if (i_cnt_isflag[2] == 1)
		i_cnt_isflag[2]++;
	else if (i_cnt_isflag[2] == 2)
	{
		i_cnt_isflag[2] = 0;
		i_cnt_isflag[1] = 0;
		i_cnt_isflag[3] = 0;
		flag = '\0';
	}
	return (flag);
}

char	if_bonus(const char *format, char flag, int *i_cnt_isflag)
{
	if (*format == '-' || *format == '0' || *format == '.'
		|| *format == '#' || *format == ' ' || *format == '+')
	{
		if (flag == '+')
			i_cnt_isflag[3] = 1;
		if (flag == '#')
			i_cnt_isflag[3] = 2;
		flag = *format;
		i_cnt_isflag[2] = 1;
		if (*format == '-' || *format == '0' || *format == '.')
			i_cnt_isflag[1] = flags_bonus(format, *format);
	}
	else if (*format >= '1' && *format <= '9')
	{
		if (flag == '+')
			i_cnt_isflag[3] = 1;
		if (flag == '#')
			i_cnt_isflag[3] = 2;
		flag = 'L';
		i_cnt_isflag[2] = 1;
		i_cnt_isflag[1] = flags_bonus(format, flag);
	}
	return (flag);
}

char	ft_format(va_list arg, const char *format, char flag, int *i_ct_isfg)
{
	if (*format == '%')
		format++;
	if (*format == 'c')
		i_ct_isfg[0] += ft_putchr_format(va_arg(arg, int), i_ct_isfg, flag);
	else if (*format == 's')
		i_ct_isfg[0] += ft_putstr(va_arg(arg, char *), i_ct_isfg, flag);
	else if (*format == 'p')
		i_ct_isfg[0] += ft_putpointer(va_arg(arg, void *), i_ct_isfg, flag);
	else if (*format == 'd' || *format == 'i')
		i_ct_isfg[0] += ft_putnbr(va_arg(arg, int), i_ct_isfg, flag);
	else if (*format == 'u')
		i_ct_isfg[0] += ft_pt_un(va_arg(arg, unsigned int), i_ct_isfg, flag);
	else if (*format == 'x')
		i_ct_isfg[0] += ft_hxlwr(va_arg(arg, unsigned int), i_ct_isfg, flag);
	else if (*format == 'X')
		i_ct_isfg[0] += ft_hxupr(va_arg(arg, unsigned int), i_ct_isfg, flag);
	else if (*format == '%')
		i_ct_isfg[0] += ft_putchr('%');
	else
		flag = if_bonus(format, flag, i_ct_isfg);
	flag = check_after_bonus(flag, i_ct_isfg);
	return (flag);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	char	flag;
	int		i_cnt_isflag[4];

	flag = '\0';
	while ((int)flag < 4)
		i_cnt_isflag[(int)flag++] = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%' || i_cnt_isflag[2])
		{
			flag = ft_format(arg, format, flag, i_cnt_isflag);
			if (*format == '%')
				format++;
		}
		else
			i_cnt_isflag[0] += ft_putchr(*format);
		format++;
		if (i_cnt_isflag[1])
			while (*format >= '0' && *format <= '9')
				format++;
	}
	va_end (arg);
	return (i_cnt_isflag[0]);
}
