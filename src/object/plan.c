/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:55 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/01 16:25:45 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static double norm(t_vec3 vect)
{

    register double value;

    value = sqrt(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z);
    return (value);
}

inline void plan(register t_obj *obj, register t_ray ray)
{
    t_vec3  tmp_v;
    t_vec3  origine;
    double  det;
    double  d;
    t_vec3  normal;

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
