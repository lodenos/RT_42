/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:46 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/12 16:36:45 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

cl_float3		get_cylinder_normale(register t_obj *obj, register t_ray ray, float det)
{
	register float		m;
	register cl_float3	a;
	register cl_float3	p;

	m = dot(ray.dir, obj->rotate) * det + dot(sub(ray.pos, obj->pos_a), obj->rotate);
	a = add(obj->pos_a, vector_mult_x(obj->rotate, m));
	p = add(ray.pos, vector_mult_x(ray.dir, det));
	obj->normal = reverse(normalize(sub(obj->pos_a, sub(obj->collision, \
						vector_mult_x(obj->rotate, dot(ray.dir, obj->rotate) * \
							det + dot(ray.pos, obj->rotate))))));
	if (obj->radius_a.y == 0)
		return (obj->normal);
	if (m > obj->radius_a.y || m < 0)
	{
		printf("here\n");
		return (-1);
	}
	return (obj->normal);
}

inline float		cylinder(register t_obj obj, register t_ray ray)
{
	register t_equ	cyl;
	register float	det;

	obj.rotate = normalize(obj.rotate);
	cyl.a = dot(ray.dir, ray.dir) - dot(ray.dir, obj.rotate) * \
		dot(ray.dir, obj.rotate);
	cyl.b = 2 * (dot(ray.dir, sub(ray.pos, obj.pos_a)) - dot(ray.dir, obj.rotate) \
			* dot(sub(ray.pos, obj.pos_a), obj.rotate));
	cyl.c = dot(sub(ray.pos, obj.pos_a), sub(ray.pos, obj.pos_a)) - \
		pow(dot(sub(ray.pos, obj.pos_a), obj.rotate), 2) - \
		obj.radius_a.x * obj.radius_a.x;
	det = cyl.b * cyl.b - 4 * cyl.a * cyl.c;
	if (det > 0)
	{
		cyl.d = (-cyl.b + sqrt(det)) / (2 * cyl.a);
		cyl.e = (-cyl.b - sqrt(det)) / (2 * cyl.a);
		if (cyl.e < cyl.d)
			return (cyl.e);
		return (cyl.d);
	}
	return (-1);
}
