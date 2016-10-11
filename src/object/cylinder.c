/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:46 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/11 15:08:22 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void cylinder(register t_obj *obj, register t_ray ray)
{
    t_evo   evo;

    evo.a = ray.b.x * ray.b.x + ray.b.z * ray.b.z;
    evo.b = 2.0 * ((ray.a.x - obj->pos.x) * ray.b.x
        + (ray.a.z - obj->pos.z) * ray.b.z);
    evo.c = (ray.a.x - obj->pos.x) * (ray.a.x - obj->pos.x)
        + (ray.a.z - obj->pos.z) * (ray.a.z - obj->pos.z)
        - obj->radius * obj->radius;
    evo.det = evo.b * evo.b - 4.0 * evo.a * evo.c;
    if (evo.det > 0)
    {
        evo.ta = (-evo.b + sqrt(evo.det)) / (2.0 * evo.a);
        evo.tb = (-evo.b - sqrt(evo.det)) / (2.0 * evo.a);
        obj->det = (evo.ta > evo.tb) ? evo.tb : evo.ta;
    }
    else
        obj->det = -1;
}
