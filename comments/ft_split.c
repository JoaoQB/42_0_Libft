/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:52:32 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/09 18:19:08 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*Count how many substrings there are in the string, depending of delimiter.
Allocate an array of arrays big enough to hold all words plus 1 to set to 0.
Allocate a string for each substr in substr array and copy the substr into it.
Free everything if we have a memory allocation error.*/

/*free each element of the array, using iteration, and the array itself.*/
static char	free_all(char **s, int count)
{
	while (count-- >= 0)//no need for iter, decrement count.
		free(*(s + count));//free each array.
	free(s);//free the whole array of arrays.
	return (NULL);//to indicate memory was fred.
}

/*allocate enough room for word. copy the word into memory allocated.
(use strlcpy to ensure string is null terminated and avoid potential
buffer overflows.) return allocated word*/
static char	*fill_subs(char const *s, size_t len)//only need len, not start and end.
{
	char *dest;//first obvs need a dest.

	dest = (char *)malloc(sizeof(char) * len);
	if (!dest || !s)//failproof
		return (NULL);
	ft_strlcpy(dest, s, len);
	return (dest);
}

/*find and return the number of words in the string.*/
/*no need for iter variable, using pointer arithmetic.
also no need for calling another function.*/
static int	subs_count(char const *s, char c)
{
	size_t	is_word;
	size_t	count;

	is_word = 1;
	count = 0;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (is_word == 0  && *s != c)//checks if we started a new subs.
		{
			is_word = 1;
			count++;
		}
		else if (*s == c)//resets switch for delimiter.
			is_word = 0;
		s++;
	}
	return (count);
}

/*allocate an array big enough to hold all the subs in s. Loop over the
string and find the start of the subs. find the end of subs.
copy the subs at the first index in our subs array. return our subs array.*/
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	i_word;
	char	**split_str;

	/*allocate the wholle array of arrays.*/
	split_str = (char **)malloc(sizeof(char *) * (subs_count(s, c) + 1));
	if (!s || !split_str)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)//while delimiter
			i++;
		i_word = i;
		while (*(s + i) != c && *(s + i))//is now a subs.
			i++;
		//fill each of the subs with the content of s.
		if (i_word < i)//checks if there's a valid substr to be allocated.
		{
			*(split_str + j++) = fill_subs(*(s + i_word), (i - i_word) + 1);
			if (!(*(split_str + j)))
				return (free_all(*(split_str + j), j));//frees all with j as counter of subs.
		}
	}
	*(split_str + j) = NULL;//adds terminating null pointer.
	return (split_str);
}
