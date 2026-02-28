/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafsanch <rafsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:46:37 by rafsanch          #+#    #+#             */
/*   Updated: 2026/02/22 18:46:37 by rafsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		i += write(1, &str[i], 1);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	num;
	char	res[12];
	int		i;
	int		count;

	count = 0;
	num = n;
	i = 0;
	if (num == 0)
		return (write(1, "0", 1));
	if (num < 0)
	{
		num = -num;
		count += write(1, "-", 1);
	}
	while (num > 0)
	{
		res[i++] = num % 10 + '0';
		num = num / 10;
	}
	while (i > 0)
		count += write(1, &res[--i], 1);
	return (count);
}

int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}
