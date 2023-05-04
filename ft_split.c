/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:01:50 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/04/26 19:06:35 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	substr_count(char const *s, int c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 1;
		s++;
	}
	return (count);
}

static char	*fill_substr(const char *src, size_t len)
{
	char	*dest;

	if (!src)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, len);
	return (dest);
}

static void	ft_free(char **strs, int count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}


char	**ft_split(char const *s, char c)
{
	char	split_strs;
	size_t	i;
	size_t	j;
	size_t	i_word;

	i = 0;
	j = 0;
	i_word = -1;
	if (!s)
		return (NULL);
	split_strs = (char **)malloc((substr_count(s, c) + 1) * sizeof(char));
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && i_word < 0)
	}
}
