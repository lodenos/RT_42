/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:22:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/11 12:16:56 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void get_normal_object(t_obj *obj, register t_ray ray,
        register float det)
{
    if (obj->type == 1)
        obj->normal = reverse(normalize(sub(obj->pos,
                sub(obj->collision, vector_mult_x(vector_mult_x(
                obj->rotate, dot(ray.dir, obj->rotate) * det +
                dot(ray.pos, obj->rotate)), (1.0 + tanf(obj->angle / 2)
                * tanf(obj->angle / 2)))))));
    else if (obj->type == 2)
        obj->normal = reverse(normalize(sub(obj->pos, sub(obj->collision,
                vector_mult_x(obj->rotate, dot(ray.dir, obj->rotate) * det +
                dot(ray.pos, obj->rotate))))));
    else if (obj->type == 3)
        obj->normal = obj->rotate;
    else if (obj->type == 4)
        obj->normal = normalize(sub(obj->collision, obj->pos));
}

void        run_raytracing(t_env *e, t_obj *obj, t_ray *ray)
{
    register float  det;
    size_t  id;

    ray->color = 0x0;
    det = check_object(obj, *ray, &id);
    if (det == -1)
        return ;
    obj[id].collision = coordinates_collision(ray->pos, ray->dir, det);
    get_normal_object(&obj[id], *ray, det);
    light(e, ray, e->c_diff, id);
}
