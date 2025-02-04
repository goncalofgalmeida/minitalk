/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: g24force <g24force@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:32:35 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/02/04 16:52:42 by g24force         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*temp;
	t_list	*list;
	t_list	*ptn;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		temp = f(lst->content);
		ptn = ft_lstnew(temp);
		if (!ptn)
		{
			ft_lstclear(&list, del);
			del(temp);
			return (0);
		}
		ft_lstadd_back(&list, ptn);
		lst = lst->next;
	}
	return (list);
}

