/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_uppercase.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:43:04 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/25 17:34:50 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_upper(unsigned int n, int *i)
{
	char	c;

	if (n > 15)
	{
		if (n / 15 > 0)
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

int	ft_hxupr(unsigned int hexupper, int *i_ct_isfg, char flag)
{
	int	i;
	int	len;

	i = 0;
	len = len_itoa_hex(hexupper);
	if (flag == '#' || (i_ct_isfg[3] == 2 && flag != '.'))
		len += 2;
	if ((flag == '0' || flag == '.') && i_ct_isfg[3] == 2)
	{
		i += ft_putstr("0X", i_ct_isfg, 0);
		i += bonus_befor_wr(len, i_ct_isfg, flag, 1);
	}
	else
	{
		i += bonus_befor_wr(len, i_ct_isfg, flag, 1);
		if (flag == '#' || i_ct_isfg[3] == 2)
			i += ft_putstr("0X", i_ct_isfg, 0);
	}
	if (hexupper == 0)
		return (i + ft_putchr('0'));
	i = put_hex_upper(hexupper, &i);
	i = bonus_after_wr(i_ct_isfg, flag, i);
	return (i);
}
