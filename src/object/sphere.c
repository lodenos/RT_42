/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:11 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/06 17:10:48 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void sphere(register t_obj *obj, register t_ray ray)
{
    register t_evo      evo;
    register cl_float3  tmp;

    evo.a = vector_scalar(ray.b, ray.b);
    tmp = vector_sub(ray.a, obj->pos);
    evo.b = 2 * (vector_scalar(ray.b, tmp));
    evo.c = vector_scalar(tmp, tmp) - obj->radius * obj->radius;
    evo.det = evo.b * evo.b - 4 * evo.a * evo.c;
    if (evo.det >= 0)
    {
        evo.ta = (-evo.b + sqrtf(evo.det)) / (2 * evo.a);
        evo.tb = (-evo.b - sqrtf(evo.det)) / (2 * evo.a);
        obj->det = (evo.ta > evo.tb) ? evo.tb : evo.ta;
    }
    else
        obj->det = -1;
}
