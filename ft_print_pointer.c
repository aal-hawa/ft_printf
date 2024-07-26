/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:23:52 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/26 16:50:51 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_pointer(unsigned long long n, int *i)
{
	char	c;

	if (n > 15)
	{
		if (n / 15 > 0)
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

int	ft_putpointer(void *ptr)
{
	unsigned long long	address;
	int					i;

	i = 0;
	if (!ptr)
		return (i += ft_putstr("0x0"));
	address = (unsigned long long) ptr;
	i += ft_putstr("0x");
	if (address == 0)
		return (i + ft_putchr('0'));
	i = put_hex_pointer(address, &i);
	return (i);
}
