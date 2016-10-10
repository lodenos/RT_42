/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:22:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/07 21:44:08 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void get_normal_object(t_obj *obj, t_ray ray)
{
    if (obj->type == 1)
        obj->normal = vector_reverse(vector_normalize(vector_sub(obj->pos,
                vector_sub(obj->collision, vector_mult_x(vector_mult_x(
                obj->rotate, vector_scalar(ray.b, obj->rotate) * obj->det +
                vector_scalar(ray.a, obj->rotate)), (1.0 + tanf(obj->angle / 2)
                * tanf(obj->angle / 2)))))));
    else if (obj->type == 2)
    {
        obj->normal = vector_reverse(vector_normalize(vector_sub(obj->pos,
                vector_sub(obj->collision, vector_mult_x(obj->rotate,
                vector_scalar(ray.b, obj->rotate) * obj->det +
                vector_scalar(ray.a, obj->rotate))))));
    }
    else if (obj->type == 3)
        obj->normal = vector_normalize(obj->rotate);
    else if (obj->type == 4)
        obj->normal = vector_normalize(vector_sub(obj->collision, obj->pos));
}

void        run_raytracing(t_env *e, t_obj *obj, t_ray *ray)
{
    register size_t id;

    ray->rgba = (t_rgba){0, 0, 0, 255};
    id = check_object(obj, ray);
    if ((int)obj[id].det == -1)
    {
        ft_putstr("-1\n");
        return ;
    }
    obj[id].collision = coordinates_collision(ray->a, ray->b, obj[id].det);
    get_normal_object(&obj[id], *ray);
    light(e, ray, e->scn.c_diff, id);
}
