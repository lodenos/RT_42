/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:24:22 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/21 23:20:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    get_scene(t_env *e, t_list *list)
{
    while (list && !ft_strstr(list->content, "{"))
        list = list->next;
    while (list && !ft_strstr(list->content, "}"))
    {
        if (ft_strstr(list->content, "cam_pos"))
            get_camera(e, ft_strconc(list->content, '(', ')'), 0);
        else if (ft_strstr(list->content, "cam_dir"))
            get_camera(e, ft_strconc(list->content, '(', ')'), 1);
        else if (ft_strstr(list->content, "render"))
            get_camera(e, ft_strconc(list->content, '(', ')'), 2);
        list = list->next;
    }
}
