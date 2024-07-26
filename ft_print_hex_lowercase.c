/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lowercase.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:40:51 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/26 21:06:56 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_lower(unsigned int n, int *i)
{
	char	c;
	int		check;

	check = 0;
	if (n > 15 && *i != -1)
	{
		if (n / 15 > 0)
			put_hex_lower(n / 16, i);
		put_hex_lower(n % 16, i);
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

int	ft_hxlwr(unsigned int hexlower)
{
	int	i;

	i = 0;
	if (hexlower == 0)
		return (i + ft_putchr('0'));
	i = put_hex_lower(hexlower, &i);
	return (i);
}
