/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:46 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/13 17:08:45 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

float		cyl2(register t_obj obj, register t_ray ray, float det, float det2)
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
			return (cyl2(obj, ray, cyl.e, cyl.d));
		return (cyl2(obj, ray, cyl.d, cyl.e));
	}
	return (-1);
}
