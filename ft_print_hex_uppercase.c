/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_uppercase.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:43:04 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/20 20:49:14 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_upper(unsigned int n, int *i)
{
	char c;
	
	if (n > 16)
	{
		if(n / 16 > 0)
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

int	ft_puthexuppercase(unsigned int hexupper)
{
	int	i;

	i = 0;
	if (hexupper == 0)
	{
		ft_putchr('0');
		return (1);
	}
	return (put_hex_upper(hexupper, &i));
}