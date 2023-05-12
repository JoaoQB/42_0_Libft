/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:57:01 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/12 15:31:24 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Description:
// Count how many substrings there are in the string, depending of delimiter.
// Allocate an array of arrays big enough to hold all words plus 1 to set to 0.
// Allocate a string for each substr in substr array and copy the substr into it.
// Free everything if we have a memory allocation error.


// Find and return the number of words in the string.
// No need for iter variable, using pointer arithmetic.
// Also no need for calling another function.
static int	substr_count(char const *s, int c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		// Checks if we started a new substring.
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		// Resets switch for delimiter.
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

// Allocate enough room for word. copy the word into memory allocated.
// (Use strlcpy to ensure string is null terminated and avoid potential
// Buffer overflows). Return allocated word
static char	*fill_substr(const char *src, size_t len)
{
	char	*dest;

	if (!src)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, len);
	return (dest);
}

// Free each element of the array, using iteration, and the array itself.
static char	**ft_free(char **strs, int count)
{
	// No need for iter, decrement count.
	while (--count >= 0)
		// Free each array.
		free(*(strs + count));
	// Free the whole array.
	free(strs);
	// To indicate memory was freed.
	return (NULL);
}

// Iterate i. Save lines. Cheeky.
static int	iterate_i(const char *s, int i, char c)
{
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

// Allocate an array big enough to hold all the subs in s.
// Loop over the string and find the start of the subs. find the end of subs.
// Copy the subs at the first index in our subs array. return our subs array.
char	**ft_split(char const *s, char c)
{
	char	**split_strs;
	int		i;
	int		j;
	int		i_word;

	// Allocate the wholle array of arrays.
	split_strs = (char **)malloc((substr_count(s, c) + 1) * sizeof(char *));
	if (!split_strs || !s)
		return (NULL);
	j = 0;
	i = 0;
	while (*(s + i))
	{
		// While delimiter
		if (*(s + i) == c)
			i++;
		i_word = i;
		// Aux function to save lines. Iterate i inside substring.
		i = iterate_i(s, i, c);
		// Fill each of the subs with the content of s.
		// Checks if there's a valid subs to be allocated.
		if (i_word < i)
		{
			*(split_strs + j++) = fill_substr(&s[i_word], (i - i_word) + 1);
			// If mem allo fails, free all with j as counter of subs.
			if (!(*(split_strs + j - 1)))
				return (ft_free(split_strs, j));
		}
	}
	// Adds terminating NULL Macro. Not the same as '\0'.
	*(split_strs + j) = NULL;
	return (split_strs);
}
