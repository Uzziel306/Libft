/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:07:09 by asolis            #+#    #+#             */
/*   Updated: 2017/01/18 17:07:10 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *prev;

	if (!lst || !(new = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	new = f(lst);
	prev = new;
	while (lst->next)
	{
		prev->next = f(lst->next);
		prev = prev->next;
		lst = lst->next;
	}
	return (new);
}
