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

static inline unsigned int  merge_diffuse(unsigned int *color, size_t n_color)
{
    register float          red;
    register float          green;
    register float          blue;
    register unsigned int   tmp_color;
    register size_t         i;

    red = 0;
    green = 0;
    blue = 0;
    i = 0;
    while (i < n_color)
    {
        red   += (float)((unsigned char)(color[i] >> 24));
        green += (float)((unsigned char)(color[i] >> 16));
        blue  += (float)((unsigned char)(color[i] >> 8));
        ++i;
    }
    tmp_color = (unsigned int)(red / n_color) << 24 |
            (unsigned int)(green / n_color) << 16 |
            (unsigned int)(blue / n_color) << 8 |
            (unsigned int)0xFF;
    return (tmp_color);
}

// TODO Exeprimental -- Teste, NO Exactly
// TODO Oui je sais ca fais plus de 25 lignes 'glodenos'->all

void                        light(t_env *e, t_ray *ray, unsigned int *c_diff, register size_t id)
{
    int             i;
    size_t          index;
    t_ray           ray_spot;
    t_obj           tmp_obj;

//-------------------------------------

    unsigned int    color = 0x0;
    register double z = 0.0;
    register double tmp;
    int             np = 0;
    float           det;

//-------------------------------------

    i = -1;
    tmp_obj = e->scn.obj[id];
    while (e->scn.spt[++i].end)
    {
        ray->color = e->scn.obj[id].color;
        ray_spot.dir = tmp_obj.collision;
        ray_spot.pos = e->scn.spt[i].pos;
        ray_spot.dir = normalize(sub(ray_spot.dir, ray_spot.pos));
        index = 0;
        det = check_object(e->scn.obj, ray_spot, &index);
        if ((det == -1) || (id == index))
        {
            diffused_light(ray, e->scn.spt[i], tmp_obj);
            tmp = specular_light(e->scn.spt[i], e->scn.obj[id]);
            if (tmp >= z)
            {
                z = tmp;
                np = i;
            }
/*
            if (e->scn.spt[i].rgba.red > color.red)
                color.red = limit_rgba(e->scn.spt[i].rgba.red);
            if (e->scn.spt[i].rgba.green > color.green)
                color.green = limit_rgba(e->scn.spt[i].rgba.green);
            if (e->scn.spt[i].rgba.blue > color.blue)
                color.blue = limit_rgba(e->scn.spt[i].rgba.blue);*/
        }
        else
        {
            diffused_light(ray, e->scn.spt[i], tmp_obj);
            ray->color = 0x0;
        }
        c_diff[i] = ray->color;
    }
    ray->color = merge_diffuse(c_diff, e->scn.n_spt);
/*    if (z > 0)
    {
        ray->rgba.red = limit_rgba(ray->rgba.red + color.red * z);
        ray->rgba.green = limit_rgba(ray->rgba.green + color.green * z);
        ray->rgba.blue = limit_rgba(ray->rgba.blue + color.blue * z);
    }*/
}
