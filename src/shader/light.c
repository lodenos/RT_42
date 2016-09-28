/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:50:04 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/28 22:32:13 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    light(t_spt *spt, t_obj *obj, size_t id, t_ray *ray)
{
    size_t  index;
    t_ray   ray_spot;
    t_obj   tmp_obj;

    tmp_obj = obj[id];
    ray_spot.b = tmp_obj.collision;
    ray_spot.a = spt[0].pos;
    ray_spot.b = vector_normalize(vector_sub(ray_spot.b, ray_spot.a));
    index = check_object(obj, &ray_spot);
    if (((int)obj[index].det == -1) || (id == index))
    {
        diffused_light(ray, spt[0], tmp_obj);
        specular_light(ray, spt[0], tmp_obj);
    }
    else
    {
        diffused_light(ray, spt[0], tmp_obj);
        ray->rgba = (t_rgba){(unsigned char)(ray->rgba.red * 0.1),
                (unsigned char)(ray->rgba.green * 0.1),
                (unsigned char)(ray->rgba.blue * 0.1), 255};
    }
}
