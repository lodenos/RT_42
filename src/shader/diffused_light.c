/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffused_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 04:50:32 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/30 16:46:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void diffused_light(t_ray *ray, register t_spt spt, register t_obj obj)
{
    register t_vec3 l;
    register double z;

    l = vector_normalize(vector_sub(obj.collision, spt.pos));
    z = -(vector_scalar(l, obj.normal) * spt.diffuse);
    // TODO   Corrige Ambient 
    ray->rgba.red = limit_rgba(((ray->rgba.red + spt.rgba.red) / 2) * z);
    ray->rgba.green = limit_rgba(((ray->rgba.green + spt.rgba.green) / 2) * z);
    ray->rgba.blue = limit_rgba(((ray->rgba.blue + spt.rgba.blue) / 2) * z);
}
