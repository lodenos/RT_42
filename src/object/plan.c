/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:55 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/04 22:29:59 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void plan(register t_obj *obj, register t_ray ray)
{
    cl_float3   tmp_v;
    cl_float3   origine;
    float       det;
    float       d;
    cl_float3   normal;

    origine.x = 0;
    origine.y = 0;
    origine.z = 0;

    tmp_v = vector_sub(obj->pos, origine);
    normal = vector_normalize(obj->rotate);
    d = sqrt(vector_scalar(tmp_v, tmp_v));
    det = -(normal.x * ray.a.x + normal.y * ray.a.y + normal.z * ray.a.z + d)
        / (normal.x * ray.b.x + normal.y * ray.b.y + normal.z * ray.b.z);
    obj->det = (det < 0) ? -1 : det;
}
