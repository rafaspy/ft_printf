/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafsanch <rafsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:46:02 by rafsanch          #+#    #+#             */
/*   Updated: 2026/01/25 17:02:17 by rafsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	res[12];
	int		i;

	num = n;
	i = 0;
	if (num == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	while (num > 0)
	{
		res[i++] = num % 10 + '0';
		num = num / 10;
	}
	while (i > 0)
	{
		write(fd, &res[--i], 1);
	}
}
