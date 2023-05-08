/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:16:09 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/08 14:03:48 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	/*first checks if current position in src is not null terminating char.
	Then if there is space available in dst by checking if size is not 0.
	Lastly if i has not reached size - 1 (to save space for '\0')*/
	while (*(src + i) && size && i < size - 1)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	/*checks if there is still the null terminating byte to copy*/
	if (size - i != 0)
		*(dst + i) = '\0';
	return (ft_strlen(src));
}
