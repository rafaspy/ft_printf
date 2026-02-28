/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafsanch <rafsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 22:49:18 by rafsanch          #+#    #+#             */
/*   Updated: 2026/02/24 22:49:18 by rafsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	char	res[10];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		res[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
	{
		count += write(1, &res[--i], 1);
	}
	return (count);
}

int	ft_puthex(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, base);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (2 + ft_puthex((unsigned long)ptr, "0123456789abcdef"));
}
