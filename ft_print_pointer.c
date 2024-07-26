/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:23:52 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/26 21:46:39 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_pointer(unsigned long long n, int *i)
{
	char	c;
	int		check;

	check = 0;
	if (n > 15 && *i != -1)
	{
		if (n / 15 > 0)
			put_hex_pointer(n / 16, i);
		put_hex_pointer(n % 16, i);
	}
	else
	{
		c = "0123456789abcdef"[n];
		check = ft_putchr(c);
		if (check == -1)
		{
			*i = -1;
			return (-1);
		}
		(*i)++;
	}
	return (*i);
}

int	ft_putpointer(void *ptr)
{
	unsigned long long	address;
	int					i;
	int					check;

	check = 0;
	i = 0;
	if (!ptr)
		return (ft_putstr("0x0"));
	address = (unsigned long long) ptr;
	check = ft_putstr("0x");
	if (check == -1)
		return (-1);
	i += check;
	if (address == 0)
	{
		check = ft_putchr('0');
		if (check == -1)
			return (-1);
		return (i + check);
	}
	i = put_hex_pointer(address, &i);
	return (i);
}
