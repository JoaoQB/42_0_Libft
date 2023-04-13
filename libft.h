/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:37:41 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/04/13 15:29:26 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(char *str);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	isascii(int c);
int	ft_isprint(int c);

#endif
