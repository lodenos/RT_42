/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/06 01:06:22 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp_last;

	if (!lst)
		return (NULL);
	if (!(tmp_last = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	tmp_last = f(lst);
	tmp = tmp_last;
	while (lst->next)
	{
		tmp->next = f(lst->next);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (tmp_last);
}
