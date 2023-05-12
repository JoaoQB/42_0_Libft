/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:57:14 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/12 14:26:51 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	tmp = (void *)malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	ft_memset(tmp, 0, size * nmemb);
	return (tmp);
}
