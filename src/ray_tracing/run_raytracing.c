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
#include <stdio.h>

inline void get_normal_object(t_obj *obj, register t_ray ray,
        register float det)
{
    if (obj->type == CONE)
        obj->normal = reverse(normalize(sub(obj->pos,
                sub(obj->collision, vector_mult_x(vector_mult_x(
                obj->rotate, dot(ray.dir, obj->rotate) * det +
                dot(ray.pos, obj->rotate)), (1.0 + tanf(obj->angle / 2)
                * tanf(obj->angle / 2)))))));
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
/*
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
*/
void        run_raytracing(t_env *e, t_obj *obj, t_ray *ray)
{
    register float  det;
    register float  reflct;
    register t_ray  *tmp_ray;

    size_t  id;

    ray->color = 0x0;
    det = check_object(obj, *ray, &id);
    if (det == -1)
        return ;
    obj[id].collision = coordinates_collision(ray->pos, ray->dir, det);
//    ft_putnbr((int)id);
    get_normal_object(&obj[id], *ray, det);
    /*bump_mapping(&obj[id]);*/
    tmp_ray->pos = obj[id].collision;
    tmp_ray->dir = reflection(&obj[id], ray);
    reflct = check_object(obj, *tmp_ray, &id);
    if (reflct != -1)
    {
      light(e, tmp_ray, e->c_diff, id);
      light(e, ray, e->c_diff, id);
      ray->color = (((ray->color * 0.5) + tmp_ray->color) / (2 * (1 + 0.5)));
    }
    else
      light(e, ray, e->c_diff, id);
}
