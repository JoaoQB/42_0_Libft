/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:28:13 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/08 22:07:33 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len > (ft_strlen(s) + 1) - start)
	{
		len = ft_strlen(s) - start;
		substr = (char *)malloc(sizeof(char) * (len + 1));
		if (!substr)
			return (NULL);
	}
	else
		substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < len)
		*(substr + i) = *(s + start + i);
	*(substr + i) = '\0';
	return (substr);
}
