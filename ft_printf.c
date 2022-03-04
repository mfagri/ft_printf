/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:44:39 by mfagri            #+#    #+#             */
/*   Updated: 2021/11/30 13:56:17 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(char c, va_list pr, int *i)
{
	if (c == '%')
		(*i) += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		(*i) += ft_putnbr(va_arg(pr, int));
	else if (c == 'c')
		(*i) += ft_putchar(va_arg(pr, int));
	else if (c == 's')
		(*i) += ft_putstr(va_arg(pr, char *));
	else if (c == 'x')
		(*i) += ft_hexa(va_arg(pr, unsigned int), 1);
	else if (c == 'X')
		(*i) += ft_hexa(va_arg(pr, unsigned int), 0);
	else if (c == 'p')
	{
		ft_putstr("0x");
		(*i) += 2;
		(*i) += ft_hexa(va_arg(pr, unsigned long), 1);
	}
	else if (c == 'u')
		(*i) += ft_unsigned(va_arg(pr, unsigned int));
	else
		(*i) += ft_putchar(c);
}

int	ft_printf(const char *forma, ...)
{
	int		i;
	va_list	pr;

	i = 0;
	va_start(pr, forma);
	while (*forma)
	{
		if (*forma == '%')
		{
			forma++;
			if (*forma == '\0')
				return (i);
			print(*forma, pr, &i);
		}
		else
		{
			ft_putchar(*forma);
			i++;
		}
		forma++;
	}
	va_end(pr);
	return (i);
}
