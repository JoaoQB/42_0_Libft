/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:48:57 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/08 22:25:55 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	/*checks if len is bigger than available string to copy from position start*/
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);//if so sets len to its value.
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < len)
		*(substr + i) = *(s + start + i);
	*(substr + i) = '\0';
	return (substr);
}
