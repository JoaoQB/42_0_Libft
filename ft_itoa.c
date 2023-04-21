/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:35:35 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/04/21 18:14:09 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		count;
	int		sign;

	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = digit_count(n);
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	result[count] = '\0';
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	while (count > 0)
	{
		result[--count] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
