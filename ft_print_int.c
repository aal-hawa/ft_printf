/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:26:28 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/21 16:09:19 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	recursive_nbr(int n, int *i)
{
	char	c;

	if (n < 0)
		return (*i);
	if (n > 9)
	{
		recursive_nbr(n / 10, i);
		recursive_nbr(n % 10, i);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
		(*i)++;
	}
	return (*i);
}

int	ft_putnbr(int n, int count_len, char flag)
{
	int i;
	int len_wr;

	len_wr = 0;
	i = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	len_wr += bonus_befor_wr(n, count_len, flag);
	len_wr += recursive_nbr(n, &i);
	len_wr = bonus_after_wr(count_len, flag, len_wr);
	return(len_wr);
}