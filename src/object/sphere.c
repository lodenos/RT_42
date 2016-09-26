/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:11 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/23 07:26:17 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void sphere(register t_obj *obj, register t_ray ray)
{
    register t_evo  evo;
    register t_vec3 vec_tmp;

    evo.a = vector_scalar(ray.b, ray.b);
    vec_tmp = vector_sub(ray.a, obj->pos);
    evo.b = 2 * (vector_scalar(ray.b, vector_sub(ray.a, obj->pos)));
    evo.c = vector_scalar(vec_tmp, vec_tmp) - obj->radius * obj->radius;
    evo.det = evo.b * evo.b - 4 * evo.a * evo.c;
    if (evo.det >= 0)
    {
        evo.ta = (-evo.b + sqrt(evo.det)) / (2 * evo.a);
        evo.tb = (-evo.b - sqrt(evo.det)) / (2 * evo.a);
        if (evo.ta > evo.tb)
        {
            obj->det = evo.tb;
            obj->collision = coordinates_collision(ray.a, ray.b, obj->det);
            obj->normal = obj->collision;
            return ;
        }
        obj->det = evo.ta;
        obj->collision = coordinates_collision(ray.a, ray.b, obj->det);
        obj->normal = obj->collision;
        return ;
    }
    obj->det = -1;
}
