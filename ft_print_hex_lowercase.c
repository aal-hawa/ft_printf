/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lowercase.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:40:51 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/20 20:49:09 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_lower(unsigned int n, int *i)
{
	char c;
	
	if (n > 16)
	{
		if(n / 16 > 0)
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

int	ft_puthexlowercase(unsigned int hexlower)
{
	int	i;

	i = 0;
	if (hexlower == 0)
	{
		ft_putchr('0');
		return (1);
	}
	return (put_hex_lower(hexlower, &i));
}