/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:39:50 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/08 13:13:21 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*works like memcpy but in a nondestructive manner. So if the memory overlaps
it won't overwrite the original src like with memcpy. Because we can't use
malloc, we can't make a new string, so we''l have to use another way to deal
with overlaping. we do so by checking if they pottentialy overlap,
and if they do, we start copying from the back, so we ensure to have already
written the chars that would pottentialy be overwriten.*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!dest && !src)
		return (NULL);
	/* checks if the adress of dest is greater than source and if so we
	copy from the end to start, in case of potential overlap.*/
	if ((char *)dest > (const char *)src)
		while (n-- > 0)// > 0 because of the --n, it iterates n as soon as it's read.
			*((char *)dest + n) = *((const char *)src + n);
	else
		while (++i < n)// < n and not <= for the same reason.
			*((char *)dest + i) = *((const char *)src + i);
	return (dest);
}
