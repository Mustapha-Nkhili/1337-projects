/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 08:25:38 by mn-khili          #+#    #+#             */
/*   Updated: 2025/10/28 20:55:40 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*h_alloc_fail(void *content, t_list **n_l, void (*del)(void *))
{
	del(content);
	ft_lstclear(n_l, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*next;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		next = ft_lstnew(content);
		if (!next)
			return (h_alloc_fail(content, &new_list, del));
		ft_lstadd_back(&new_list, next);
		lst = lst->next;
	}
	return (new_list);
}
