/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_uppercase.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:43:04 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/22 18:06:13 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_upper(unsigned int n, int *i)
{
	char	c;

	if (n > 16)
	{
		if (n / 16 > 0)
			put_hex_upper(n / 16, i);
		put_hex_upper(n % 16, i);
	}
	else
	{
		c = "0123456789ABCDEF"[n];
		ft_putchr(c);
		(*i)++;
	}
	return (*i);
}

int	ft_hxupr(unsigned int hexupper, int count_len, char flag)
{
	int	i;
	int	len;

	i = 0;
	len = len_itoa_hex(hexupper);
	if (flag == '#')
		len += 2;
	i += bonus_befor_wr(len, count_len, flag, 1);
	if (flag == '#')
		i += ft_putstr("0x", 0, 0);
	if (hexupper == 0)
	{
		i += ft_putchr('0');
		return (i);
	}
	i = put_hex_upper(hexupper, &i);
	i = bonus_after_wr(count_len, flag, i);
	return (i);
}
