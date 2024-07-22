/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lowercase.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:40:51 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/22 18:05:53 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_lower(unsigned int n, int *i)
{
	char	c;

	if (n > 16)
	{
		if (n / 16 > 0)
			put_hex_lower(n / 16, i);
		put_hex_lower(n % 16, i);
	}
	else
	{
		c = "0123456789abcdef"[n];
		ft_putchr(c);
		(*i)++;
	}
	return (*i);
}

int	ft_hxlwr(unsigned int hexlower, int count_len, char flag)
{
	int	i;
	int	len;

	i = 0;
	len = len_itoa_hex(hexlower);
	if (flag == '#')
		len += 2;
	i += bonus_befor_wr(len, count_len, flag, 1);
	if (flag == '#')
		i += ft_putstr("0x", 0, 0);
	if (hexlower == 0)
	{
		i += ft_putchr('0');
		return (i);
	}
	i = put_hex_lower(hexlower, &i);
	i = bonus_after_wr(count_len, flag, i);
	return (i);
}
