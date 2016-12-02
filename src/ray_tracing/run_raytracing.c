/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:22:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/01 14:09:20 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void get_normal_object(t_obj *obj, register t_ray ray,
        register float det)
{
	register float		k;
	register float		m;
	register cl_float3	a;
	register cl_float3	q;

    if (obj->type == CONE)
        obj->normal = reverse(normalize(sub(obj->pos_a,
                sub(obj->collision, vector_mult_x(vector_mult_x(
                obj->rotate, dot(ray.dir, obj->rotate) * det +
                dot(ray.pos, obj->rotate)), (1.0f + tanf(obj->angle / 2.0f)
                * tanf(obj->angle / 2.0f)))))));
    else if (obj->type == CYLINDER)
        obj->normal = reverse(normalize(sub(obj->pos_a, sub(obj->collision,
                vector_mult_x(obj->rotate, dot(ray.dir, obj->rotate) * det +
                dot(ray.pos, obj->rotate))))));
    else if (obj->type == PLAN)
        obj->normal = obj->rotate;
	else if (obj->type == TRIANGLE)
		obj->normal = normalize(cross(sub(obj->pos_b, obj->pos_a), sub(obj->pos_c, obj->pos_a)));
	else if (obj->type == SPHERE)
        obj->normal = normalize(sub(obj->collision, obj->pos_a));
    else if (obj->type == ELLIPSOID)
	{
 //     obj->normal = normalize(sub(obj->collision, obj->pos_a));
		obj->normal = reverse(get_ellipsoid_normale(*obj, ray, det));
	}
	else if (obj->type == TORUS)
	{
		k = dot(sub(obj->collision, obj->pos_a), ray.dir);
		a = sub(obj->collision, vector_mult_x(ray.dir, k));
		m = sqrt(ABS(pow(obj->radius_b.x, 2.0f) - (k * k)));
		obj->normal = normalize(sub(sub(obj->collision, a), vector_mult_x(sub(obj->pos_a, a), (m / (obj->radius_a.x + m)))));

/*	a = (cl_float3){obj->collision.x, obj->collision.y, 0.0f};
	q = vector_mult_x(a, obj->radius_a.x / sqrt(pow(obj->collision.x, 2) + pow(obj->collision.y, 2)));
	obj->normal = normalize(sub(obj->collision, q));
*/	}
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

    if (obj_tmp.reflexion > 0)
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
        bump_mapping(&obj_tmp);
        light(e, id, obj_tmp, ray);
    }
    else
    {
        bump_mapping(&obj_tmp);
        light(e, id, obj_tmp, ray);
    }
}
