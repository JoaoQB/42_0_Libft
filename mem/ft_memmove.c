/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:15:41 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/12 14:27:15 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!dest && !src)
		return (NULL);
	if ((char *)dest > (const char *)src)
		while (n-- > 0)
			*((char *)dest + n) = *((const char *)src + n);
	else
		while (++i < n)
			*((char *)dest + i) = *((const char *)src + i);
	return (dest);
}
