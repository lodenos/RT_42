/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:12:41 by anespoul          #+#    #+#             */
/*   Updated: 2016/11/30 12:09:09 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

/*inline float		triangle(register t_obj obj, register t_ray ray)
{
	register cl_float3	edge0;
	register cl_float3	edge1;
	register cl_float3	edge2;
	register cl_float3	Phit;
	register cl_float3	c;
	register float		t;

	obj.rotate = normalize(cross(sub(obj.pos_a, obj.pos_c), sub(obj.pos_b, obj.pos_c)));
	if (dot(obj.rotate, ray.dir) == 0)
		return (-1);
	t = -(dot(obj.rotate, ray.pos) + dot(obj.rotate, obj.pos_b)) \
		/ dot(obj.rotate, ray.dir);
	if (t <= 0)
		return (-1);
	Phit = add(ray.pos, vector_mult_x(ray.dir, t));
	edge0 = sub(obj.pos_b, obj.pos_a);
	edge1 = sub(obj.pos_c, obj.pos_b);
	edge2 = sub(obj.pos_a, obj.pos_c);
	c = cross(edge0, sub(Phit, obj.pos_a));
	if (dot(obj.rotate, c) < 0)
		return (-1);
	c = cross(edge1, sub(Phit, obj.pos_b));
	if (dot(obj.rotate, c) < 0)
		return (-1);
	c = cross(edge2, sub(Phit, obj.pos_c));
	if (dot(obj.rotate, c) < 0)
		return (-1);
	printf("%lf\n", t);
	return (t);
}*/

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
	if (det > -0.000001 && det < 0.000001)
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
