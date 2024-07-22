/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:03:12 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/22 18:05:30 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	recursive_uns_nbr(unsigned int n, int *i)
{
	char	c;

	if (n > 9)
	{
		if (n / 10 > 0)
			recursive_uns_nbr(n / 10, i);
		recursive_uns_nbr(n % 10, i);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
		(*i)++;
	}
	return (*i);
}

int	ft_pt_un(unsigned int n, int count_len, char flag)
{
	int	i;

	i = 0;
	i += bonus_befor_wr(n, count_len, flag, 0);
	if (n == 0)
	{
		ft_putchr('0');
		i++;
		return (i);
	}
	i = recursive_uns_nbr(n, &i);
	i = bonus_after_wr(count_len, flag, i);
	return (i);
}
