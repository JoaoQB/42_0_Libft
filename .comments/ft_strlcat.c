/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:05:03 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/08 18:14:22 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dst && !size)
		return (0);
	i = 0;
	while (*(dst + i) && i < size)
		i++;
	j = 0;
	while (*(src + j) && (i + j + 1) < size)
	{
		*(dst + i + j) = *(src + j);
		j++;
	}
	if (i + j != size)//works with i and i + j?
		*(dst + i + j) = '\0';
	return (i + ft_strlen(src));
}
