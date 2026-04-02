/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafsanch <rafsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 00:47:08 by rafsanch          #+#    #+#             */
/*   Updated: 2026/01/25 16:58:01 by rafsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*res;

	len = count_digits(n);
	res = malloc((len + 1));
	if (!res)
		return (NULL);
	num = n;
	res[len] = '\0';
	if (num == 0)
		res[0] = '0';
	if (num < 0)
	{
		num = -num;
		res[0] = '-';
	}
	while (num > 0)
	{
		res[--len] = (num % 10 + '0');
		num = num / 10;
	}
	return (res);
}
