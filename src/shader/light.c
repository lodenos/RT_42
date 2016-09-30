/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:50:04 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/30 16:41:04 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline t_rgba    merge_diffuse(t_rgba *rgba, size_t n_color)
{
    double  red;
    double  green;
    double  blue;
    t_rgba  color;
    size_t  i;

    red = 0;
    green = 0;
    blue = 0;
    i = 0;
    while (i < n_color)
    {
        red += rgba[i].red;
        green += rgba[i].green;
        blue += rgba[i].blue;
        ++i;
    }
    color.red = (unsigned char)(red / n_color);
    color.green = (unsigned char)(green / n_color);
    color.blue = (unsigned char)(blue / n_color);
    return (color);
}

void                    light(t_env *e, t_rgba *c_diff, size_t id)
{
    // TODO Exeprimental -- Teste, NO Exactly
    // TODO Oui je sais ca fais plus de 25 lignes 'glodenos'->all
    int             i;
    size_t          index;
    t_ray           ray_spot;
    t_obj           tmp_obj;

//-------------------------------------
    t_rgba          color;
    color = (t_rgba){0, 0, 0, 255};
    register double z;
    register double tmp;
    int             np;
    np = 0;
    z = 0.0;
//-------------------------------------

    i = -1;
    tmp_obj = e->obj[id];
    while (e->spt[++i].end)
    {
        e->ray.rgba = e->obj[id].rgba;
        ray_spot.b = tmp_obj.collision;
        ray_spot.a = e->spt[i].pos;
        ray_spot.b = vector_normalize(vector_sub(ray_spot.b, ray_spot.a));
        index = check_object(e->obj, &ray_spot);
        if (((int)e->obj[index].det == -1) || (id == index))
        {
            diffused_light(&e->ray, e->spt[i], tmp_obj);
            tmp = specular_light(e->spt[i], e->obj[id]);
            if (tmp >= z)
            {
                z = tmp;
                np = i;
            }

    if (e->spt[i].rgba.red > color.red)
        color.red = limit_rgba(e->spt[i].rgba.red);
    if (e->spt[i].rgba.green > color.green)
        color.green = limit_rgba(e->spt[i].rgba.green);
    if (e->spt[i].rgba.blue > color.blue)
        color.blue = limit_rgba(e->spt[i].rgba.blue);


//-----------------------------------------------------
      
        //-----------------------------------------------------
        }
        else
        {
            diffused_light(&e->ray, e->spt[i], tmp_obj);
            e->ray.rgba = (t_rgba){0, 0, 0, 255};
        }
        c_diff[i] = e->ray.rgba;
    }
    e->ray.rgba = merge_diffuse(c_diff, e->n_spt);
/*
    if (e->spt[np].rgba.red > color.red)
        color.red = e->spt[np].rgba.red;
    if (e->spt[np].rgba.green > color.green)
        color.green = e->spt[np].rgba.green;
    if (e->spt[np].rgba.blue > color.blue)
        color.blue = e->spt[np].rgba.blue;
*/
    if (z > 0)
    {
        e->ray.rgba.red = limit_rgba(e->ray.rgba.red + color.red * z);
        e->ray.rgba.green = limit_rgba(e->ray.rgba.green + color.green * z);
        e->ray.rgba.blue = limit_rgba(e->ray.rgba.blue + color.blue * z);
    }
}
