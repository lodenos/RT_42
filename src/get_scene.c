/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 07:43:57 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/19 20:36:01 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void	get_scene(char *file, t_env *e)
{
    int i;
    
    (void)file;
    i = -1;
    e->n_obj = 4;
    e->n_spt = 1;

    e->obj = (t_obj*)malloc(sizeof(t_obj) * (e->n_obj + 1));
    e->spt = (t_spt*)malloc(sizeof(t_spt) * (e->n_spt + 1));

    e->spt[0].rgb = 0xFFFFFFFF;
    e->spt[0].pos.x = 800;
    e->spt[0].pos.y = 800;
    e->spt[0].pos.z = 800;
    e->spt[0].light = 100;
    e->spt[0].end = 1;
    e->spt[1].end = 0;

    ++i;
    e->obj[i].rgb = 0xFF00FFFF;
    e->obj[i].pos.x = 200;
    e->obj[i].pos.y = 200;
    e->obj[i].pos.z = -10;
    e->obj[i].r = 600;
    e->obj[i].end = 1;
    e->obj[i].ft = &(sphere);
    ++i;
    e->obj[i].rgb = 0xFF0000FF;
    e->obj[i].pos.x = 1000;
    e->obj[i].pos.y = 200;
    e->obj[i].pos.z = 0;
    e->obj[i].r = 600;
    e->obj[i].end = 1;
    e->obj[i].ft = &(sphere);
    ++i;
    e->obj[i].rgb = 0xFFFF00FF;
    e->obj[i].pos.x = -200;
    e->obj[i].pos.y = -200;
    e->obj[i].pos.z = 0;
    e->obj[i].r = 600;
    e->obj[i].end = 1;
    e->obj[i].ft = &(sphere);
    ++i;
    e->obj[i].rgb = 0x0000FFFF;
    e->obj[i].pos.x = 600;
    e->obj[i].pos.y = 1000;
    e->obj[i].pos.z = -10;
    e->obj[i].r = 600;
    e->obj[i].end = 1;
    e->obj[i].ft = &(sphere);
    ++i;
    e->obj[i].end = 0;
}
