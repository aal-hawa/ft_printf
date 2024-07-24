/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:23:52 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/24 20:52:31 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_pointer(unsigned long long n, int *i)
{
	char	c;

	if (n > 16)
	{
		if (n / 16 > 0)
			put_hex_pointer(n / 16, i);
		put_hex_pointer(n % 16, i);
	}
	else
	{
		c = "0123456789abcdef"[n];
		ft_putchr(c);
		(*i)++;
	}
	return (*i);
}

int	len_itoa_16(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	ptr_nil(int *i_ct_isfg, char flag, int i)
{
	i += bonus_befor_wr(5, i_ct_isfg, flag, 1);
	i += ft_putstr("(nil)", 0, 0);
	i = bonus_after_wr(i_ct_isfg, flag, i);
	return (i);
}

int	ft_putpointer(void *ptr, int *i_ct_isfg, char flag)
{
	unsigned long long	address;
	int					i;

	i = 0;
	if (!ptr)
		return (ptr_nil(i_ct_isfg, flag, i));
	address = (unsigned long long) ptr;
	if ((flag == '0' || flag == '.'))
	{
		i += ft_putstr("0x", i_ct_isfg, 0);
		if ((flag == '0' || flag == '.'))
			i += bonus_befor_wr((len_itoa_16(address)), i_ct_isfg, flag, 1);
	}
	else
	{
		i += bonus_befor_wr((len_itoa_16(address) + 2), i_ct_isfg, flag, 1);
		i += ft_putstr("0x", i_ct_isfg, 0);
	}
	if (address == 0)
		return (i + ft_putchr('0'));
	i = put_hex_pointer(address, &i);
	i = bonus_after_wr(i_ct_isfg, flag, i);
	return (i);
}
