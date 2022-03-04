/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:29:40 by mfagri            #+#    #+#             */
/*   Updated: 2021/12/03 12:29:46 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *forma, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_hexa(unsigned long n, int a);
int		ft_unsigned(unsigned int n);
void	print(char c, va_list pr, int *i);
#endif
