/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:23:52 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/22 14:01:30 by Anas Al Haw      ###   ########.fr       */
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

int	ft_putpointer(void *ptr, int count_len, char flag)
{
	unsigned long long	address;
	int					i;

	i = 0;
	address = (unsigned long long) ptr;
	i += bonus_befor_wr((len_itoa_16(address) + 2), count_len, flag, 16);
	i += ft_putstr("0x", 0, 0);
	if (address == 0)
	{
		ft_putchr('0');
		i++;
		return (i);
	}
	i = put_hex_pointer(address, &i);
	i = bonus_after_wr(count_len, flag, i);
	return (i);
}
