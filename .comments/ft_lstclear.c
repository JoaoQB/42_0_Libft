/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:41:38 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/12 13:59:34 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst && del)
	{
		while (*lst)
		{
			temp = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(temp, del);
		}
	}
	// No need to double free using the code below. already fred with above function.
	// free(*lst);
	// *lst = NULL;
}
