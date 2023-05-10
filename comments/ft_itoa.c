/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:35:35 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/10 16:10:46 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)//if n = 0, returns immediately 1.
		return (1);
	if (n < 0)
		count++;//1 extra for minus char.
	while (n != 0)//keep dividing n by 10 until 1 int is reached.
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
	while (count > 0)//assigns the int to char from right to left, using modulus.
	{
		result[--count] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)//if negative, first element of array is a minus/
		result[0] = '-';
	return (result);
}
