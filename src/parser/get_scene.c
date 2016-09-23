/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:50:55 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/23 06:41:39 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    get_scene(t_env *e, char *file)
{
    /* TODO Parser a faire sans leaks et sans liste chaine */
    int i;

    (void)file;
    i = -1;
    e->n_obj = 4;
    e->n_spt = 1;

    e->obj = (t_obj*)malloc(sizeof(t_obj) * (e->n_obj + 1));
    e->spt = (t_spt*)malloc(sizeof(t_spt) * (e->n_spt + 1));

    e->spt[0].rgba = (t_rgba){255, 150, 255, 255};
    e->spt[0].pos.x = 400;
    e->spt[0].pos.y = 400;
    e->spt[0].pos.z = -100;
    e->spt[0].light = 100;
    e->spt[0].end = 1;
    e->spt[1].end = 0;
    ++i;
    e->obj[i].rgba = (t_rgba){255, 0, 255, 255};
    e->obj[i].pos.x = -5;
    e->obj[i].pos.y = 0;
    e->obj[i].pos.z = 500;
    e->obj[i].radius = 20;
    e->obj[i].end = 1;
    e->obj[i].ft = &(sphere);
    ++i;
    e->obj[i].end = 0;
}
