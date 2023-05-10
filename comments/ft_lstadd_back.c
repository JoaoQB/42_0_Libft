/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jqueijo- <jqueijo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:08:01 by jqueijo-          #+#    #+#             */
/*   Updated: 2023/05/10 16:28:05 by jqueijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)//if lst is empty, new will be already at the back.
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);//uses ft_lstlast to check the pointer for last.
		last->next = new;
	}
}
