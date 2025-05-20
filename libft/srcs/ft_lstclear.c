/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:59:35 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/05/20 11:59:03 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nxt_node;

	if (lst)
	{
		while (*lst)
		{
			nxt_node = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = nxt_node;
		}
	}
}
