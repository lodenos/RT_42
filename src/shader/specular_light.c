/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 05:01:11 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/23 07:35:42 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline t_rgba    rgba_mult(register t_rgba a, register double z)
{
    register size_t max;
    register t_rgba color;

    max = (size_t)(a.red * z);
    color.red = (max > 255) ? 0xFF : (unsigned char)max;
    max = (size_t)(a.green * z);
    color.green = (max > 255) ? 0xFF : (unsigned char)max;
    max = (size_t)(a.blue * z);
    color.blue = (max > 255) ? 0xFF : (unsigned char)max;
    max = (size_t)(a.alpha * z);
    color.alpha = (max > 255) ? 0xFF : (unsigned char)max;
    return (color);
}

void                    specular_light(t_ray *ray, t_spt spt, t_obj obj)
{
    register t_vec3 l;
    register t_vec3 n;
    register t_vec3 r;
    register double z;

    l = vector_normalize(vector_sub(obj.normal, spt.pos));
    n = vector_normalize(vector_sub(obj.normal, obj.pos));
    r = vector_add(l, vector_mult_x(vector_mult_x(n, 2),
                vector_scalar(vector_reverse(n), l)));
    z = pow(vector_scalar(vector_reverse(l), r), 28);
    ray->rgba = limit_rgba(ray->rgba, rgba_mult(spt.rgba, z));
}
