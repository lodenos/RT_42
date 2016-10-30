/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:22:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/28 06:50:14 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void get_normal_object(t_obj *obj, register t_ray ray,
        register float det)
{
    if (obj->type == CONE)
        obj->normal = reverse(normalize(sub(obj->pos,
                sub(obj->collision, vector_mult_x(vector_mult_x(
                obj->rotate, dot(ray.dir, obj->rotate) * det +
                dot(ray.pos, obj->rotate)), (1.0f + tanf(obj->angle / 2.0f)
                * tanf(obj->angle / 2.0f)))))));
    else if (obj->type == CYLINDER)
        obj->normal = reverse(normalize(sub(obj->pos, sub(obj->collision,
                vector_mult_x(obj->rotate, dot(ray.dir, obj->rotate) * det +
                dot(ray.pos, obj->rotate))))));
    else if (obj->type == PLAN)
        obj->normal = obj->rotate;
    else if (obj->type == SPHERE)
        obj->normal = normalize(sub(obj->collision, obj->pos));
    else if (obj->type == TORUS)
        return ;
}

void        run_raytracing(t_env *e, t_obj *obj, t_ray *ray)
{
    register float  det;
    size_t          id;
    t_obj           obj_tmp;
    unsigned int    color;

    ray->color = 0x0;
    det = check_object(obj, *ray, &id, NO_MASK);
    if ((int)det == -1)
        return ;
    obj_tmp = obj[id];
    obj_tmp.collision = coordinates_collision(ray->pos, ray->dir, det);
    get_normal_object(&obj_tmp, *ray, det);

//------------------------------------------------------------------------------
    if (id == 5)
    {

        ray->pos = obj_tmp.collision;
        ray->dir = sub(ray->dir, vector_mult_x(vector_mult_x(obj_tmp.normal,
                dot(obj_tmp.normal, ray->dir)), 2));
        det = check_object(obj, *ray, &id, 5);
        if (det == -1)
            return ;
        color = ray->color;
        obj_tmp = obj[id];
        obj_tmp.collision = coordinates_collision(ray->pos, ray->dir, det);
        get_normal_object(&obj_tmp, *ray, det);
        obj_tmp.type_bump = 1;
//        bump_mapping(&obj_tmp);
        light(e, id, obj_tmp, ray);
    }
    else
    {
        obj_tmp.type_bump = 1;
//        bump_mapping(&obj_tmp);
        light(e, id, obj_tmp, ray);
    }
//------------------------------------------------------------------------------
}
