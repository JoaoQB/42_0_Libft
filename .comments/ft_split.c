/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:52:32 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/10 15:56:47 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Count how many substrings there are in the string, depending of delimiter.
Allocate an array of arrays big enough to hold all words plus 1 to set to 0.
Allocate a string for each substr in substr array and copy the substr into it.
Free everything if we have a memory allocation error.*/

/*find and return the number of words in the string.*/
/*no need for iter variable, using pointer arithmetic.
also no need for calling another function.*/
static int	substr_count(char const *s, int c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)//checks if we started a new subs.
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)//resets switch for delimiter.
			in_word = 0;
		s++;
	}
	return (count);
}

/*allocate enough room for word. copy the word into memory allocated.
(use strlcpy to ensure string is null terminated and avoid potential
buffer overflows.) return allocated word*/
static char	*fill_substr(const char *src, size_t len)//only need len, not start and end.
{
	char	*dest;//first obvs need a dest.

	if (!src)//failproof
		return (NULL);
	dest = (char *)malloc(sizeof(char) * len);
	if (!dest)//failproof
		return (NULL);
	ft_strlcpy(dest, src, len);
	return (dest);
}

/*free each element of the array, using iteration, and the array itself.*/
static char	ft_free(char **strs, int count)
{
	while (--count >= 0)//no need for iter, decrement count.
		free(*(strs + count));//free each array.
	free(strs);//free the whole array of arrays.
	return (NULL);//to indicate memory was fred.
}

/*allocate an array big enough to hold all the subs in s. Loop over the
string and find the start of the subs. find the end of subs.
copy the subs at the first index in our subs array. return our subs array.*/
char	**ft_split(char const *s, char c)
{
	char	**split_strs;
	int		i;
	int		j;
	int		i_word;

	/*allocate the wholle array of arrays.*/
	split_strs = (char **)malloc((substr_count(s, c) + 1) * sizeof(char *));
	if (!split_strs || !s)
		return (NULL);
	j = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)//while delimiter
			i++;
		i_word = i;
		while (*(s + i) && *(s + i) != c)//is now a subs.
			i++;
		//fill each of the subs with the content of s.
		if (i_word < i)//checks if there's a valid substr to be allocated.
		{
			*(split_strs + j++) = fill_subs(*(s + i_word), (i - i_word) + 1);
			if (!(*(split_strs + j)))
				return (free_all(*(split_strs + j), j));//frees all with j as counter of subs.
		}
	}
	*(split_strs + j) = NULL;//adds terminating null pointer.
	return (split_strs);
}
