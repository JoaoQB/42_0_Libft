/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:25:34 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/08 12:44:45 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest) //is this needed?
		return (NULL);
	while (i < n)
	{
		*((char *)dest + i) = *((const char *)src + i); //cast as const so the memory is not modifiable.
		i++;
	}
	return (dest);
}
