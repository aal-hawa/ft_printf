/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:26:28 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/27 17:05:42 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	recursive_nbr(int n, int *i)
{
	char	c;
	int		check;

	check = 0;
	if (n < 0)
		return (*i);
	if (n > 9 && *i != -1)
	{
		recursive_nbr(n / 10, i);
		recursive_nbr(n % 10, i);
	}
	else
	{
		c = n + '0';
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

int	ft_putnbr(int n)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		check = ft_putchr('-');
		if (check == -1)
			return (-1);
		n = -n;
		i++;
	}
	i = recursive_nbr(n, &i);
	return (i);
}
