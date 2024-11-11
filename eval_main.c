/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:18:06 by jqueijo-          #+#    #+#             */
/*   Updated: 2024/11/11 15:20:25 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Meant for evaluations

// libftTester
// Memcopys
// Bonus: Explain difference between linked list and array of pointers

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void ft_split_test(const char *str, char delimiter)
{
	char **result = ft_split(str, delimiter);
	int i = 0;

	printf("Input: \"%s\" | Delimiter: '%c'\n", str, delimiter);
	printf("Result:\n");

	if (result == NULL)
	{
		printf("NULL result (allocation failure or invalid input)\n\n");
		return;
	}

	while (result[i])
	{
		printf("  [%d]: \"%s\"\n", i, result[i]);
		free(result[i]);  // Free each individual string
		i++;
	}
	free(result);  // Free the array of strings

	printf("\n");
}

int main(void)
{
	// char	*string;

	// string = NULL;
	// Test cases for ft_split
	ft_split_test("hello world this is a test", ' ');       // Simple space delimiter
	ft_split_test(",,,a,,,b,,,c,,,", ',');                  // Multiple delimiters in a row
	ft_split_test("split this string by spaces", ' ');      // Normal sentence with spaces
	ft_split_test("singleword", ' ');                       // No delimiter present
	ft_split_test("", ',');                                 // Empty string
	ft_split_test("start,mid,end", ',');                    // Comma-delimited words
	ft_split_test(",,,,,", ',');                            // Only delimiters
	// ft_split_test(string, ' ');

	return 0;
}
