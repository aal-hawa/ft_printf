/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:46:20 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/24 21:10:37 by Anas Al Haw      ###   ########.fr       */
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

int	len_itoa_hex(unsigned int n)
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

int	count_nut_zero(int count, int deff_len, int *i_cnt_isflag, char flag)
{
	if ((flag == '0' || flag == '.') && i_cnt_isflag[3] == 1)
	{
		ft_putchr('+');
		i_cnt_isflag[3] = 0;
		if (flag == '0' )
			count--;
		else
			deff_len++;
	}
	while (count > 0)
	{
		if (count == 1 && i_cnt_isflag[3] == 1)
		{
			ft_putchr('+');
			break ;
		}
		count--;
		if (flag == 'L')
			ft_putchr(' ');
		else
			ft_putchr('0');
	}
	return (deff_len);
}

int	bonus_befor_wr(int n, int *i_cnt_isflag, char flag, int ismake_len)
{
	int	deff_len;
	int	count;

	deff_len = 0;
	count = i_cnt_isflag[1];
	if (flag == '0' || flag == '.' || flag == 'L')
	{
		if (ismake_len == 0)
			n = len_itoa(n);
		if (i_cnt_isflag[1] < n && !i_cnt_isflag[3])
			return (0);
		if (count >= n)
			count -= n;
		deff_len = count;
		deff_len = count_nut_zero(count, deff_len, i_cnt_isflag, flag);
	}
	else if (n > 0 && (flag == ' ' || flag == '+'))
		return (ft_putchr(flag));
	return (deff_len);
}

int	bonus_after_wr(int *i_cnt_isflag, char flag, int len_wr)
{
	if (i_cnt_isflag[1] && (flag == '-' || i_cnt_isflag[3]))
	{
		i_cnt_isflag[1] -= len_wr;
		while (i_cnt_isflag[1] > 0)
		{
			i_cnt_isflag[1]--;
			ft_putchr(' ');
			len_wr++;
		}
	}
	return (len_wr);
}
