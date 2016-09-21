/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:28:13 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 01:20:48 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    get_spot(t_env *e, char *data, int s, int index)
{
    char **xyz;

    xyz = ft_strsplit(data, ' ');
    if (index == 0)
        e->spt[s].rgb = (t_rgb){(unsigned char)ft_atoi(xyz[0]),
            (unsigned char)ft_atoi(xyz[1]),
            (unsigned char)ft_atoi(xyz[2])};
    else if (index == 1)
        e->spt[s].pos = (t_vec3){ft_atoi(xyz[0]), ft_atoi(xyz[1]),\
            ft_atoi(xyz[2])};
    free(xyz);
}

void    get_spotinfo(t_env *e, t_list *list, int s)
{
    while (list && !ft_strstr(list->content, "{"))
        list = list->next;
    while (list && !ft_strstr(list->content, "}"))
    {
        if (ft_strstr(list->content, "color"))
            get_spot(e, ft_strconc(list->content, '(', ')'), s, 0);
        else if (ft_strstr(list->content, "pos"))
            get_spot(e, ft_strconc(list->content, '(', ')'), s, 1);
        else if (ft_strstr(list->content, "power"))
            e->spt[s].light = (size_t)ft_atoi(ft_strconc(list->content, '(', ')'));
        list = list->next;
    }
}
