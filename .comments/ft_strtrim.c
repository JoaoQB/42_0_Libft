/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:31:01 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/09 14:50:54 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	end = ft_strlen(s1);
	start = 0;
	if (!s1)
		return (NULL);
	/*checks for set char in beg and end. gets an index for new substr.*/
	while (s1[start] && ft_strchr(set, *(s1 + start)))
		start++;
	while (end > start && ft_strchr(set, *(s1 + end)))
		end--;
	return (ft_substr(s1, start, (end - start) + 1));
}//if end 10 and start 5, you want to copy 5chars. (10 - 5) + 1 for NULL.
