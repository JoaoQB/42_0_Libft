/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:33:11 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/04/19 16:42:15 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little || *little == '\0')
		return ((char *)big);
	if (len == 0 && !big)
		return (NULL);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while ((little[j]) && (big[i + j] == little[j]) && (i + j < len))
			j++;
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}