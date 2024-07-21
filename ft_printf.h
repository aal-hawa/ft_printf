/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anas Al Hawamda <aal-hawa@student.42abu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:50:05 by Anas Al Haw       #+#    #+#             */
/*   Updated: 2024/07/21 17:34:59 by Anas Al Haw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_putstr(char *s, int count_len, char flag);
int	ft_putchr(char c);
int	ft_putchr_format(char c, int count_len, char flag);
int	ft_putnbr(int n, int count_len, char flag);
int	ft_printf(const char *format, ...);
int ft_putpointer(void * ptr);
int	ft_put_unsigned(unsigned int n);
int	ft_puthexlowercase(unsigned int hexlower, char flag);
int	ft_puthexuppercase(unsigned int hexupper, char flag);
int bonus_befor_wr(int n, int count_len, char flag);
int	bonus_after_wr(int count_len, char flag, int len_wr);


# endif