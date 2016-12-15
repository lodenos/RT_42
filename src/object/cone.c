/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:26 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:24:51 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

float				cone2(register t_obj obj, register t_ray ray, \
		register float det, register float det2)
{
	register float		m;
	register float		a;

	m = dot(ray.dir, obj.rotate) * det + \
		dot(sub(ray.pos, obj.pos_a), obj.rotate);
	a = dot(ray.dir, obj.rotate) * det2 + \
		dot(sub(ray.pos, obj.pos_a), obj.rotate);
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
	register t_equ	a;
	register float	det;
	register float	i;

	i = tanf(obj.angle / 2.0f) * tanf(obj.angle / 2.0f);
	obj.rotate = normalize(obj.rotate);
	a.a = dot(ray.dir, ray.dir) - (1 + i) * pow(dot(ray.dir, obj.rotate), 2);
	a.b = 2 * (dot(ray.dir, sub(ray.pos, obj.pos_a)) - (1 + i) * \
		dot(ray.dir, obj.rotate) * dot(sub(ray.pos, obj.pos_a), obj.rotate));
	a.c = dot(sub(ray.pos, obj.pos_a), sub(ray.pos, obj.pos_a)) - \
			(1 + i) * pow(dot(sub(ray.pos, obj.pos_a), obj.rotate), 2);
	if ((det = a.b * a.b - 4.0f * a.a * a.c) > 0.0f)
	{
		a.d = (-a.b + sqrtf(det)) / (2.0f * a.a);
		a.e = (-a.b - sqrtf(det)) / (2.0f * a.a);
		if (a.d < 0 && a.e < 0)
			return (-1);
		else if (a.d < 0 && a.e > 0)
			return (cone2(obj, ray, a.e, a.d));
		else if (a.e < 0 && a.d > 0)
			return (cone2(obj, ray, a.d, a.e));
		return (a.d > a.e) ? \
		cone2(obj, ray, a.e, a.d) : cone2(obj, ray, a.d, a.e);
	}
	return (-1.0f);
}
