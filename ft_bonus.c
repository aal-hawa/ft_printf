/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:46:20 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/22 13:46:20 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_itoa(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int bonus_befor_wr(int n, int count_len, char flag, int divide)
{
	int len_wr;
	int	deff_len;
	
	deff_len = 0;
	len_wr = 0;
	if (count_len && (flag == '0' || flag == '.'|| flag == 'L'))
	{
		if (divide == 10)
			len_wr = len_itoa(n);
		else
			len_wr = n;
		count_len -= len_wr;
		deff_len = count_len;
		while (count_len)
		{
			count_len--;
			if (flag == 'L')
				ft_putchr(' ');
			else
				ft_putchr('0');

		}
	}
	else if (n > 0 && (flag == ' ' || flag == '+'))
	{
		ft_putchr(flag);
		return (1);
	}
	return (deff_len);
}

int	bonus_after_wr(int count_len, char flag, int len_wr)
{
	if (count_len && flag == '-')
	{
		count_len -= len_wr;
		while (count_len)
		{
			count_len--;
			ft_putchr(' ');
			len_wr++;
		}
	}
	return (len_wr);
}