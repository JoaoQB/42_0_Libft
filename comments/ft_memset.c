/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:04:56 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/08 12:18:03 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	/*casts s + i as char, to ensure we treat the memory pointed to by s as
	individual bytes. This is important because c is an integer and we need
	to store it as a single byte in memory.*/
	while (i < n)
	{
		*((char *)s + i) = c;
		i++;
	}
	return (s);
}
/*The reason it works without casting c as char is due to the way the assignment
works in C. When assigning an int value to a char variable or memory location,
the value is automatically truncated to fit within the range of a char
(typically 8 bits). The assignment *((char *)s + i) = c; will store only the
lower 8 bits of c in the memory location.
Therefore, even if c is an int value, it can be assigned to a char memory
location without explicit casting. The behavior is defined by the C language
standard.*/
