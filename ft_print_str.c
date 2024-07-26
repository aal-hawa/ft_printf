/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:26:34 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/26 16:50:57 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	i_check;

	i_check = 0;
	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
	{
		i_check = ft_putchr(*s);
		if (i_check == -1)
			return (-1);
		i++;
		s++;
	}
	return (i);
}
