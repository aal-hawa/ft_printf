/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:26:22 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/22 16:20:25 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchr_format(char c, int count_len, char flag)
{
	int	i;

	i = 0;
	i += bonus_befor_wr(1, count_len, flag, 1);
	write(1, &c, 1);
	i++;
	if (flag == '-')
		return (bonus_after_wr(count_len, flag, i));
	return (i);
}
