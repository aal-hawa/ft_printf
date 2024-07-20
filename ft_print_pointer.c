/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:23:52 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/20 20:33:31 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_pointer(unsigned long long n, int *i)
{
	char c;
	
	if (n > 16)
	{
		if(n / 16 > 0)
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

int	ft_putpointer(void * ptr)
{
	unsigned long long address;
	int	i;

	i = 0;
	address = (unsigned long long) ptr;
	i += ft_putstr("0x");
	if (address == 0)
	{
		ft_putchr('0');
		return (1);
	}
	return (put_hex_pointer(address, &i));
}