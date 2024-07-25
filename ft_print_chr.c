/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:26:22 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/25 18:51:52 by aal-hawa         ###   ########.fr       */
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
