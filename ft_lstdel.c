/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:58:01 by asolis            #+#    #+#             */
/*   Updated: 2017/01/18 16:58:04 by asolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *prev;

	if (*alst)
	{
		list = *alst;
		while (list)
		{
			prev = list;
			list = list->next;
			del(prev->content, prev->content_size);
			free(prev);
		}
	}
	*alst = NULL;
}
