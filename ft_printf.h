/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:50:05 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/22 19:02:57 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putstr(char *s, int count_len, char flag);
int	ft_putchr(char c);
int	ft_putchr_format(char c, int count_len, char flag);
int	ft_putnbr(int n, int count_len, char flag);
int	ft_printf(const char *format, ...);
int	ft_putpointer(void *ptr, int count_len, char flag);
int	ft_pt_un(unsigned int n, int count_len, char flag);
int	ft_hxlwr(unsigned int hexlower, int count_len, char flag);
int	ft_hxupr(unsigned int hexupper, int count_len, char flag);
int	bonus_befor_wr(int n, int count_len, char flag, int ismake_len);
int	bonus_after_wr(int count_len, char flag, int len_wr);
int	len_itoa_hex(unsigned int n);

#endif