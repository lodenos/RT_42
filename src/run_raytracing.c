/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 21:53:16 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 00:57:55 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static void fill_color(t_ray *ray, t_obj *obj)
{
    ray->rgb.blue = obj->rgb.blue;
    ray->rgb.green = obj->rgb.green;
    ray->rgb.red = obj->rgb.red;
}

void        run_raytracing(t_spt *spt, t_obj *obj, t_ray *ray)
{
    int     i;

    (void)spt;
    i = -1;
    ray->tmin = 20000;
    while (obj[++i].end)
    {
        obj[i].det = obj[i].ft(obj[i], *ray);
        coordinates_collision(&obj[i], *ray);
        if (0 <= obj[i].det && obj[i].det <= ray->tmin)
        {
            ray->tmin = obj[i].det;
            ray->index = i;
        }
    }
    if (obj[ray->index].det == -1)
        return ;
    fill_color(ray, &obj[ray->index]);
    light(spt, obj[ray->index], ray);
}
