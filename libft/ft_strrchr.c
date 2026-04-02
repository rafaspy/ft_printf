/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafsanch <rafsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:11:12 by rafsanch          #+#    #+#             */
/*   Updated: 2026/01/25 20:12:58 by rafsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	character;
	const char		*res;

	character = (unsigned char)c;
	res = NULL;
	while (*s)
	{
		if (*s == character)
			res = s;
		s++;
	}
	if (character == '\0')
		return ((char *)s);
	return ((char *) res);
}
