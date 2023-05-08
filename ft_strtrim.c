/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:21:02 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/08 23:30:33 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	while (*s1 && ft_strchr(set, *(s1 + start)))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, *(s1 + end)))
		end--;
	return (ft_substr(s1, start, (end - start) + 1));
}
