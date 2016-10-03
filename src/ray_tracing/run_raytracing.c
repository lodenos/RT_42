/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:22:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/02 23:16:58 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void get_normal_object(t_obj *obj, t_ray *ray)
{
    t_vec3  vec;

    vec = ray->b;

    if (obj->ft == &cone)
        obj->normal = vector_normalize(vector_sub(obj->collision, obj->pos));
    else if (obj->ft == &cylinder)
    {
        obj->normal = vector_reverse(vector_normalize(vector_sub(obj->pos,
                vector_sub(obj->collision, vector_mult_x(obj->rotate,
                vector_scalar(ray->b, obj->rotate) * obj->det +
                vector_scalar(ray->a, obj->rotate))))));
    }
    else if (obj->ft == &plan)
        obj->normal = vector_normalize(obj->rotate);
    else if (obj->ft == &sphere)
        obj->normal = vector_normalize(vector_sub(obj->collision, obj->pos));
    else if (obj->ft == &torus)
        ;
    ray->b = vec;
}

void        run_raytracing(t_env *e, t_obj *obj, t_ray *ray)
{
    register size_t id;

    ray->rgba = (t_rgba){0, 0, 0, 255};
    id = check_object(obj, ray);
    if ((int)obj[id].det == -1)
        return ;
    obj[id].collision = coordinates_collision(ray->a, ray->b, obj[id].det);
    get_normal_object(&e->obj[id], ray);
    light(e, e->c_diff, id);
}
