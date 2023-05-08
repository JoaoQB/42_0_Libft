/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:58:08 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/08 15:53:42 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* checks if LIBFT_H has not been defined before in the code.
If it hasn't been defined, the code following this directive will be included;
otherwise, it will be skipped. This is often used as a header guard to prevent
multiple inclusions of the same header file.*/
#ifndef LIBFT_H

/*Defines LIBFT_H. Uppercase and Underscore adheres to naming conventions
for C macros.*/
# define LIBFT_H

# include <string.h> //for string manipulation
# include <unistd.h> //system calls, write
# include <stdlib.h> //memory allocation
# include <stddef.h> //types and macros like NULL and size_t

/*Defines a structure named s_list and creates a typedef for it called t_list.
It has two members:
Content is a member of type void so it can hold a pointer to any data type.
Represents the content stored in a node of the list.
Next is a pointer to another structure of the same type s_list. It represents
a link to the next node.*/
typedef struct s_list
{
	void 			*content;
	struct s_list	*next;
}	t_list;
/*after defining the structure, t_list creates a typedef that associates the
name t_list with the structure s_list. It allows to use t_list as an alias for
struct s_list.*/

void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
size_t	strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif //Marks the end of the conditional block started by #ifndef directive.
