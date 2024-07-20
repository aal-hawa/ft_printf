/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:03:12 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/20 20:31:16 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	recursive_uns_nbr(unsigned int n, int *i)
{
	char	c;

	if (n > 9)
	{
		if ( n / 10 > 0)
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

int	ft_put_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if(n == 0)
	{
		ft_putchr('0');
		return (1);
	}
	return (recursive_uns_nbr(n, &i));
}