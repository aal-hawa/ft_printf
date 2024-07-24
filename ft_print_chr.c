/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:26:22 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/23 18:46:55 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchr_format(char c, int *i_ct_isfg, char flag)
{
	int	i;

	i = 0;
	i += bonus_befor_wr(1, i_ct_isfg, flag, 1);
	write(1, &c, 1);
	i++;
	if (flag == '-' || flag == '3')
		return (bonus_after_wr(i_ct_isfg, flag, i));
	return (i);
}
