/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:26 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/05 15:25:08 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void cone(register t_obj *obj, register t_ray ray)
{
    register t_evo  evo;

    evo.a = ray.b.x * ray.b.x + ray.b.z *ray.b.z - ray.b.y * ray.b.y *
        obj->angle;
    evo.b = 2 * ((ray.a.x - obj->pos.x) * ray.b.x +
            (ray.a.z - obj->pos.z) * ray.b.z -
            (ray.a.y - obj->pos.y) * ray.b.y * obj->angle);
    evo.c = ((ray.a.x - obj->pos.x) * (ray.a.x - obj->pos.x)) +
            ((ray.a.z - obj->pos.z) * (ray.a.z - obj->pos.z)) -
            ((ray.a.y - obj->pos.y) * (ray.a.y - obj->pos.y)) * obj->angle  - 
            obj->radius * obj->radius;
    evo.det = evo.b * evo.b - 4 * (evo.a * evo.c);
    if (evo.det >= 0)
    {
        evo.ta = (-evo.b + sqrtf(evo.det)) / (2 * evo.a);
        evo.tb = (-evo.b - sqrtf(evo.det)) / (2 * evo.a);
        obj->det = (evo.ta > evo.tb) ? evo.tb : evo.ta;
    }
    else
        obj->det = -1;
}
