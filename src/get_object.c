/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:27:20 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 01:18:45 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static void o_type(t_env *e, char *type, int o)
{
    if (ft_strstr(type, "plan"))
        e->obj[o].ft = &(plan);
    else if (ft_strstr(type, "sphere"))
        e->obj[o].ft = &(sphere);
    else if (ft_strstr(type, "cone"))
        e->obj[o].ft = &(cone);
    else if (ft_strstr(type, "torus"))
        e->obj[o].ft = &(torus);
    else if (ft_strstr(type, "cylinder"))
        e->obj[o].ft = &(cylinder);
}

static void get_obj(t_env *e, char *data, int o, int index)
{
    char    **xyz;

    xyz = ft_strsplit(data, ' ');
    if (index == 0)
        e->obj[o].rgb = (t_rgb){(unsigned char)ft_atoi(xyz[0]),
            (unsigned char)ft_atoi(xyz[1]),
            (unsigned char)ft_atoi(xyz[2]),};
    else if (index == 1)
        e->obj[o].pos = (t_vec3){ft_atoi(xyz[0]), ft_atoi(xyz[1]),\
            ft_atoi(xyz[2])};
    else if (index == 2)
        e->obj[o].rot = (t_vec3){ft_atoi(xyz[0]), ft_atoi(xyz[1]),\
            ft_atoi(xyz[2])};
    free(xyz);
}

static void get_objectinfo(t_env *e, t_list *list, int o)
{
    while (list && !ft_strstr(list->content, "{"))
        list = list->next;
    while (list && !ft_strstr(list->content, "}"))
    {
        if (ft_strstr(list->content, "color"))
            get_obj(e, ft_strconc(list->content, '(', ')'), o, 0);
        else if (ft_strstr(list->content, "pos"))
            get_obj(e, ft_strconc(list->content, '(', ')'), o, 1);
        else if (ft_strstr(list->content, "rot"))
            get_obj(e, ft_strconc(list->content, '(', ')'), o, 2);
        else if (ft_strstr(list->content, "size"))
            e->obj[o].r = ft_atoi(ft_strconc(list->content, '(', ')'));
        list = list->next;
    }
}

static void init_obj(t_env *e, int index, int s, int o)
{
    if (index == 0)
    {
        e->spt[s].rgb = (t_rgb){255, 255, 255};
        e->spt[s].pos = (t_vec3){800, 800, 800};
        e->spt[s].light = 100;
        e->spt[s].end = 1;
    }
    else
    {
        e->obj[o].rgb = (t_rgb){0, 0, 0};
        e->obj[o].pos = (t_vec3){0, 0, 0};
        e->obj[o].r = 0;
        e->obj[o].det = 20000;
        e->obj[o].end = 1;
    }
}

void    get_object(t_env *e, t_list *list, int s, int o)
{
    while (list && !ft_strstr(list->content, "{"))
        list = list->next;
    while (list && !ft_strstr(list->content, "}"))
    {
        if (ft_strstr(list->content, "spot"))
        {
            init_obj(e, 0, s, o);
            get_spotinfo(e, list, s);
            s++;
        }
        else if (ft_strstr(list->content, "object"))
        {
            init_obj(e, 1, s, o);
            o_type(e, ft_strconc(list->content, '(', ')'), o);
            get_objectinfo(e, list, o);
            o++;
        }
        list = list->next;
        if (ft_strstr(list->next->content, "object") || \
                ft_strstr(list->next->content, "spot"))
            list = list->next;
    }
    e->obj[o].end = 0;
    e->spt[s].end = 0;
}
