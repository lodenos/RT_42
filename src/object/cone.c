/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:26 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/13 17:07:00 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

float			cone2(register t_obj obj, register t_ray ray, float det, float det2)
{
	register float		m;
	register float		a;

	m = dot(ray.dir, obj.rotate) * det + dot(sub(ray.pos, obj.pos_a), obj.rotate);
	a = dot(ray.dir, obj.rotate) * det2 + dot(sub(ray.pos, obj.pos_a), obj.rotate);
	if (obj.radius_a.y == 0)
		return (det);
	if (m > obj.radius_a.y || m < 0)
	{
		if (a > obj.radius_a.y || a < 0)
			return (-1);
		else
			return (det2);
	}
	return (det);
}


inline float		cone(register t_obj obj, register t_ray ray)
{
	register t_equ	cone;
	register float	det;
	register float	a;

	a = tanf(obj.angle / 2.0f) * tanf(obj.angle / 2.0f);
	obj.rotate = normalize(obj.rotate);
	cone.a = dot(ray.dir, ray.dir) - (1 + a) * pow(dot(ray.dir, obj.rotate), 2);
	cone.b = 2 * (dot(ray.dir, sub(ray.pos, obj.pos_a)) - (1 + a) * \
			dot(ray.dir, obj.rotate) * \
			dot(sub(ray.pos, obj.pos_a), obj.rotate));
	cone.c = dot(sub(ray.pos, obj.pos_a), sub(ray.pos, obj.pos_a)) - \
			(1 + a) * pow(dot(sub(ray.pos, obj.pos_a), obj.rotate), 2);
	if ((det = cone.b * cone.b - 4.0f * cone.a * cone.c) > 0.0f)
	{
		cone.d = (-cone.b + sqrtf(det)) / (2.0f * cone.a);
		cone.e = (-cone.b - sqrtf(det)) / (2.0f * cone.a);
		if (cone.d < 0 && cone.e < 0)
			return (-1);
		else if (cone.d < 0 && cone.e > 0)
			return (cone2(obj, ray, cone.e, cone.d));
		else if (cone.e < 0 && cone.d > 0)
			return (cone2(obj, ray, cone.d, cone.e));
		return (cone.d > cone.e) ? cone2(obj,ray, cone.e, cone.d) : cone2(obj, ray, cone.d, cone.e);
	}
	return (-1.0f);
}
