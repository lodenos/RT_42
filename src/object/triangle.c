/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:12:41 by anespoul          #+#    #+#             */
/*   Updated: 2016/12/02 13:02:23 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline float		triangle(register t_obj obj, register t_ray ray)
{
	cl_float3 e1;
	cl_float3 e2;
	cl_float3 p;
	cl_float3 q;
	cl_float3 t;
	float det;
	float inv_det;
	float u;
	float v;
	float t2;

	e1 = sub(obj.pos_b, obj.pos_a);
	e2 = sub(obj.pos_c, obj.pos_a);
	p = cross(ray.dir, e2);
	det = dot(e1, p);
	if (det > -EPSILON && det < EPSILON)
		return (-1);
	inv_det = 1.f / det;
	t = sub(ray.pos, obj.pos_a);
	u = dot(t, p) * inv_det;
	if (u < 0.f || u > 1.f)
		return (-1);
	q = cross(t, e1);
	v = dot(ray.dir, q) * inv_det;
	if (v < 0.f || u + v > 1.f)
		return (-1);
	t2 = dot(e2, q) * inv_det;
	if (t2 > 0.000001)
		return (t2);
	return (-1);
}
