/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:46 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/28 13:12:25 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void cylinder(register t_obj *obj, register t_ray ray)
{
    register t_evo  evo;

    evo.a = ray.b.x * ray.b.x + ray.b.z * ray.b.z;
    evo.b = 2 * ((ray.a.x - obj->pos.x) * ray.b.x                              \
            + (ray.a.z - obj->pos.z) * ray.b.z);
    evo.c = (ray.a.x - obj->pos.x) * (ray.a.x - obj->pos.x)                    \
            + (ray.a.z - obj->pos.z) * (ray.a.z - obj->pos.z)
            - obj->radius * obj->radius;
    evo.det = evo.b * evo.b - 4 * evo.a * evo.c;
    if (evo.det > 0)
    {
        evo.ta = (-evo.b + sqrt(evo.det)) / (2 * evo.a);
        evo.tb = (-evo.b - sqrt(evo.det)) / (2 * evo.a);
        obj->det = (evo.ta > evo.tb) ? evo.tb : evo.ta;
    }
    obj->det = -1;
}
