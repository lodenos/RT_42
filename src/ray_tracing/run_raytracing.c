/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:22:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/30 15:51:33 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void  get_normal_object(t_obj *obj, t_ray *ray)
{
    (void)ray;
    double m;

    if (obj->ft == &cone)
         obj->normal = vector_normalize(vector_sub(obj->collision, obj->pos));
    else if (obj->ft == &cylinder)
    {
        m = vector_scalar(ray->b, obj->rotate)* obj->det + vector_scalar(ray->a, obj->rotate);
        obj->normal = vector_reverse(vector_normalize(vector_sub(obj->pos, vector_sub(obj->collision, vector_mult_x(obj->rotate, m)))));
    }
/*        obj->normal.x = 0;
        obj->normal.y = 2 * obj->collision.y;
        obj->normal.z = 2 * obj->collision.z -1;
        obj->normal = vector_normalize(obj->normal);*/
    else if (obj->ft == &plan)
        obj->normal = vector_normalize(obj->rotate);
    else if (obj->ft == &sphere)
        obj->normal = vector_normalize(vector_sub(obj->collision, obj->pos));
    else if (obj->ft == &torus)
        ;
}

void                run_raytracing(t_env *e, t_obj *obj, t_ray *ray)
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
