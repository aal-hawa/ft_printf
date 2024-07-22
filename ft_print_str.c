/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:26:34 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/22 16:50:10 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int count_len, char flag)
{
	int	i;
	int	len;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	while (s[len])
		len++;
	i += bonus_befor_wr(len, count_len, flag, 1);
	while (*s)
	{
		write(1, s, 1);
		i++;
		s++;
	}
	if (flag == '-')
		i = bonus_after_wr(count_len, flag, i);
	return (i);
}
