/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:32:35 by gjose-fr          #+#    #+#             */
/*   Updated: 2024/11/06 11:03:38 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = ft_lstnew(f(lst));
	if (!new_lst)
		return (NULL);
	while (lst)
	{
		ft_lstiter(lst, f);
	}
} */
