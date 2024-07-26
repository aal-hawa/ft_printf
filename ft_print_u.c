/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:03:12 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/26 16:53:12 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	recursive_uns_nbr(unsigned int n, int *i)
{
	char	c;
	int		i_check;

	i_check = 0;
	if (n > 9 && *i != -1)
	{
		if (n / 10 > 0)
			recursive_uns_nbr(n / 10, i);
		recursive_uns_nbr(n % 10, i);
	}
	else
	{
		c = n + '0';
		i_check = ft_putchr(c);
		if (i_check == -1)
		{
			*i = -1;
			return (-1);
		}
		(*i)++;
	}
	return (*i);
}

int	ft_pt_un(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i = ft_putchr('0');
		return (i);
	}
	i = recursive_uns_nbr(n, &i);
	return (i);
}
