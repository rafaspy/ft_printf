/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafsanch <rafsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:12:49 by rafsanch          #+#    #+#             */
/*   Updated: 2026/01/18 20:52:13 by rafsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		character;
	size_t				i;

	str = (const unsigned char *)s;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == character)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
