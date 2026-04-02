/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafsanch <rafsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:10:58 by rafsanch          #+#    #+#             */
/*   Updated: 2026/01/30 22:26:57 by rafsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_count_one_word(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**arr;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	arr = (char **)ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[j] = ft_substr(s, i, ft_count_one_word(&s[i], c));
			if (!arr[j])
				return (ft_free(arr, j));
			j++;
			i += ft_count_one_word(&s[i], c);
		}
		else
			i++;
	}
	return (arr);
}
