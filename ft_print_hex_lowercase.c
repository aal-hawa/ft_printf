/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lowercase.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:40:51 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/24 20:46:11 by Anas Al Haw      ###   ########.fr       */
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

int	ft_hxlwr(unsigned int hexlower, int *i_ct_isfg, char flag)
{
	int	i;
	int	len;

	i = 0;
	len = len_itoa_hex(hexlower);
	if (flag == '#' || (i_ct_isfg[3] == 2 && flag != '.'))
		len += 2;
	if ((flag == '0' || flag == '.') && i_ct_isfg[3] == 2)
	{
		i += ft_putstr("0x", i_ct_isfg, 0);
		i += bonus_befor_wr(len, i_ct_isfg, flag, 1);
	}
	else
	{
		i += bonus_befor_wr(len, i_ct_isfg, flag, 1);
		if (flag == '#' || i_ct_isfg[3] == 2)
			i += ft_putstr("0x", i_ct_isfg, 0);
	}
	if (hexlower == 0)
		return (i + ft_putchr('0'));
	i = put_hex_lower(hexlower, &i);
	i = bonus_after_wr(i_ct_isfg, flag, i);
	return (i);
}
