/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:23:31 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/07/20 15:33:02 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	manage_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strchr(buffer, '\n'))
	{
		while (*(buffer + i) != '\n')
			i++;
		i++;
		while (*(buffer + i))
			*(buffer + j++) = *(buffer + i++);
		while (*(buffer + j))
			*(buffer + j++) = '\0';
	}
	else
	{
		while (i < BUFFER_SIZE)
			*(buffer + i++) = '\0';
	}
}

char	*create_line(char *temp)
{
	char	*line;
	int		i;
	int		nl;

	i = 0;
	nl = 1;
	if (!temp)
		return (NULL);
	if (ft_strchr(temp, '\n'))
		nl = 2;
	while (*(temp + i) && *(temp + i) != '\n')
		i++;
	line = ft_calloc(i + nl, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (*(temp + i) && *(temp + i) != '\n')
	{
		*(line + i) = *(temp + i);
		i++;
	}
	if (nl == 2)
		*(line + i) = '\n';
	return (line);
}

char	*read_line_loop(int fd, char *buffer, char *temp, int rchars)
{
	while (rchars > 0)
	{
		if (!temp)
			temp = ft_calloc(BUFFER_SIZE + 1, 1);
		temp = ft_join_and_free(temp, buffer);
		if (ft_strchr(temp, '\n'))
			break ;
		manage_buffer(buffer);
		rchars = read(fd, buffer, BUFFER_SIZE);
	}
	return (temp);
}

char	*read_line(int fd, char *buffer)
{
	char	*temp;
	int		rchars;

	temp = NULL;
	if (*buffer)
	{
		temp = create_line(buffer);
		if (ft_strchr(temp, '\n'))
			return (temp);
		manage_buffer(buffer);
	}
	rchars = read(fd, buffer, BUFFER_SIZE);
	if (rchars < 0)
	{
		free(temp);
		return (NULL);
	}
	return (read_line_loop(fd, buffer, temp, rchars));
}

char	*ft_join_and_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j])
		dest[i++] = s2[j];
	*(dest + i) = '\0';
	free (s1);
	return (dest);
}
