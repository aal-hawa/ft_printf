/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:26:34 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/25 17:15:16 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_null(char *s, int count_len, char flag)
{
	int	i;

	if (count_len == -1 && flag == -1)
	{
		i = 0;
		while (*s)
		{
			write(1, s, 1);
			i++;
			s++;
		}
		return (i);
	}
	i = 6;
	i += bonus_befor_wr(6, &count_len, flag, 1);
	write(1, "(null)", 6);
	i = bonus_after_wr(&count_len, flag, i);
	return (i);
}

int	ft_putstr(char *s, int *i_ct_isfg, char flag)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!i_ct_isfg)
		return (print_null(s, -1, -1));
	if (!s)
		return (print_null(s, i_ct_isfg[1], flag));
	while (s[len])
		len++;
	if (i_ct_isfg[3] == 1)
		i_ct_isfg[3] = 2;
	i += bonus_befor_wr(len, i_ct_isfg, flag, 1);
	while (*s)
	{
		write(1, s, 1);
		i++;
		s++;
	}
	if (flag == '-' || flag == '3')
		i = bonus_after_wr(i_ct_isfg, flag, i);
	return (i);
}
