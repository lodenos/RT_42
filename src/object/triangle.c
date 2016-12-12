/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:12:41 by anespoul          #+#    #+#             */
/*   Updated: 2016/12/02 13:32:08 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline float		triangle(register t_obj obj, register t_ray ray)
{
	register cl_float3	p;
	register cl_float3	q;
	register cl_float3	t;
	register t_equ		tri;

	p = cross(ray.dir, sub(obj.pos_c, obj.pos_a));
	tri.a = dot(sub(obj.pos_b, obj.pos_a), p);
	if (tri.a > -EPSILON && tri.a < EPSILON)
		return (-1);
	tri.b = 1.f / tri.a;
	t = sub(ray.pos, obj.pos_a);
	tri.c = dot(t, p) * tri.b;
	if (tri.c < 0.f || tri.c > 1.f)
		return (-1);
	q = cross(t, sub(obj.pos_b, obj.pos_a));
	tri.d = dot(ray.dir, q) * tri.b;
	if (tri.d < 0.f || tri.c + tri.d > 1.f)
		return (-1);
	tri.e = dot(sub(obj.pos_c, obj.pos_a), q) * tri.b;
	if (tri.e > 0.000001)
		return (tri.e);
	return (-1);
}
