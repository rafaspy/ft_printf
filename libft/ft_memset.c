/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafsanch <rafsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 22:21:06 by rafsanch          #+#    #+#             */
/*   Updated: 2026/01/18 20:52:01 by rafsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*res;

	i = 0;
	res = (unsigned char *)b;
	while (len > 0)
	{
		res[i++] = (unsigned char)c;
		len--;
	}
	return (b);
}
