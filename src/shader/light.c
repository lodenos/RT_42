/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:50:04 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/11 15:06:04 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline t_rgba    merge_diffuse(t_rgba *rgba, size_t n_color)
{
    register float  red;
    register float  green;
    register float  blue;
    register t_rgba color;
    register size_t i;

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

void                    light(t_env *e, t_ray *ray, t_rgba *c_diff,
        register size_t id)
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
    tmp_obj = e->scn.obj[id];
    while (e->scn.spt[++i].end)
    {
        ray->rgba = e->scn.obj[id].rgba;
        ray_spot.b = tmp_obj.collision;
        ray_spot.a = e->scn.spt[i].pos;
        ray_spot.b = vector_normalize(vector_sub(ray_spot.b, ray_spot.a));
        index = check_object(e->scn.obj, &ray_spot);
        if (((int)e->scn.obj[index].det == -1) || (id == index))
        {
            diffused_light(ray, e->scn.spt[i], tmp_obj);
            tmp = specular_light(e->scn.spt[i], e->scn.obj[id]);
            if (tmp >= z)
            {
                z = tmp;
                np = i;
            }
            if (e->scn.spt[i].rgba.red > color.red)
                color.red = limit_rgba(e->scn.spt[i].rgba.red);
            if (e->scn.spt[i].rgba.green > color.green)
                color.green = limit_rgba(e->scn.spt[i].rgba.green);
            if (e->scn.spt[i].rgba.blue > color.blue)
                color.blue = limit_rgba(e->scn.spt[i].rgba.blue);
        }
        else
        {
            diffused_light(ray, e->scn.spt[i], tmp_obj);
            ray->rgba = (t_rgba){0, 0, 0, 255};
        }
        c_diff[i] = ray->rgba;
    }
    ray->rgba = merge_diffuse(c_diff, e->scn.n_spt);
    if (z > 0)
    {
        ray->rgba.red = limit_rgba(ray->rgba.red + color.red * z);
        ray->rgba.green = limit_rgba(ray->rgba.green + color.green * z);
        ray->rgba.blue = limit_rgba(ray->rgba.blue + color.blue * z);
    }
}
