/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:32:41 by jqueijo-          #+#    #+#             */
/*   Updated: 2024/04/17 10:39:57 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_atodbl(char *s)
{
	long	int_part;
	double	fract_part;
	double	pow;
	int		sign;

	int_part = 0;
	fract_part = 0;
	pow = 1;
	sign = 1;
	while((*s >= '\t' && *s <= '\r') || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while ((*s >= '0' && *s <= '9') && *s && *s != '.')
		int_part = (int_part * 10) + (*s++ - '0');
	if ('.' == *s)
		++s;
	while ((*s >= '0' && *s <= '9') && *s)
	{
		pow /= 10;
		fract_part = fract_part + (*s++ - '0') * pow;
	}
	return ((int_part + fract_part) * sign);
}
