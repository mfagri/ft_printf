/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:02:37 by mfagri            #+#    #+#             */
/*   Updated: 2021/11/30 15:08:56 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += (ft_unsigned(n / 10));
		i += (ft_unsigned(n % 10));
	}
	else
		i += (ft_putchar(n + 48));
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += (ft_putstr("-214748364"));
		n = 8;
	}
	if (n < 0)
	{
		i += (ft_putchar('-'));
		n = -n;
	}
	if (n > 9)
	{
		i += (ft_putnbr(n / 10));
		i += (ft_putnbr(n % 10));
	}
	else
		i += (ft_putchar(n + 48));
	return (i);
}

int	ft_hexa(unsigned long n, int a)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_hexa(n / 16, a);
	}
	if (n % 16 < 10)
	{
		i += ft_putchar((n % 16) + 48);
	}
	else
	{
		if (a == 1)
			i += ft_putchar((n % 16) + 87);
		else
			i += ft_putchar((n % 16) + 55);
	}
	return (i);
}
