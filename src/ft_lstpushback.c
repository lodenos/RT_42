/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 22:56:47 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/21 22:57:20 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    ft_lstpushback(t_list **blist, void const *content, size_t content_size)
{
    t_list  *list;

    list = *blist;
    if (list)
    {
        while (list->next)
            list = list->next;
        list->next = ft_lstnew(content, content_size);
    }
    else
        *blist = ft_lstnew(content, content_size);
}
