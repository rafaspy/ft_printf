/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafsanch <rafsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:39:47 by rafsanch          #+#    #+#             */
/*   Updated: 2026/01/26 20:14:09 by rafsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*s;
	size_t				i;
	unsigned char		*d;

	if (!dst && !src)
	{
		return (NULL);
	}
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	while (n-- > 0)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
