/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:50:05 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/26 15:55:18 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putstr(char *s);
int	ft_putchr(char c);
int	ft_putnbr(int n);
int	ft_printf(const char *format, ...);
int	ft_putpointer(void *ptr);
int	ft_pt_un(unsigned int n);
int	ft_hxlwr(unsigned int hexlower);
int	ft_hxupr(unsigned int hexupper);
int	len_itoa_hex(unsigned int n);

#endif