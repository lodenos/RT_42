/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:14:44 by anespoul          #+#    #+#             */
/*   Updated: 2016/12/02 12:55:32 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

cl_float3	get_ellipsoid_normale(register t_obj obj, register t_ray ray,\
		register float det)
{
	obj.normal = sub(obj.collision, obj.pos_a);
	obj.normal.x = 2.0f * obj.normal.x / (obj.radius_a.x * obj.radius_a.x);
	obj.normal.y = 2.0f * obj.normal.y / (obj.radius_a.y * obj.radius_a.y);
	obj.normal.z = 2.0f * obj.normal.z / (obj.radius_a.z * obj.radius_a.z);
	return (obj.normal);
}

float		ellipsoid(register t_obj obj, register t_ray ray)
{
	register cl_float3	oc;
	register cl_float3	dir;
	register float a;
	register float b;
	register float c;
	register float d;
	register float t1;
	register float t2;
	register float t;

	oc = sub(ray.pos, obj.pos_a);
	dir = ray.dir;
	normalize(dir);

	a = (dir.x * dir.x) / (obj.radius_a.x * obj.radius_a.x) + (dir.y * dir.y) / (obj.radius_a.y * obj.radius_a.y) + (dir.z * dir.z) / (obj.radius_a.z * obj.radius_a.z);

	b = (2.0f * oc.x * dir.x) / (obj.radius_a.x * obj.radius_a.x) + (2.0f * oc.y * dir.y) / (obj.radius_a.y * obj.radius_a.y) + (2.0f * oc.z * dir.z) / (obj.radius_a.z * obj.radius_a.z);

	c = (oc.x * oc.x) / (obj.radius_a.x * obj.radius_a.x) + (oc.y * oc.y) / (obj.radius_a.y * obj.radius_a.y) + (oc.z * oc.z) / (obj.radius_a.z * obj.radius_a.z) - 1.0f;

	d = ((b * b) - (4.0f * a * c));

	if (d < 0.f || a == 0.f || b == 0.f || c == 0.f)
		return (-1);
	d = sqrt(d);
	t1 = (-b + d) / (2.0f * a);
	t2 = (-b - d) / (2.0f * a);

	if (t1 <= EPSILON && t2 <= EPSILON)
		return (-1);
	obj.radius_b.x = (t1 <= EPSILON || t2 <= EPSILON);
	t = 0.0f;
	if (t1 <= EPSILON)
		t = t2;
	else
	{
		if (t2 <= EPSILON)
			t = t1;
		else
			t = (t1 < t2) ? t1 : t2;
	}
	if (t < EPSILON)
		return (-1);
	return (t);
}
/*
cl_float3	get_ellipsoid_normale(register t_obj obj, register t_ray ray,\
		register float det)
{
	register float  a;
	register float  a1;
	register float  a2;
	register float  b;
	register float  c;
	register float	d;
	register cl_float3 cmid;
	register cl_float3 r;

	a1 = 2 * obj.radius_b.x * dot(ray.dir, obj.rotate);
	a2 = pow(obj.radius_a.x, 2) + 2 * obj.radius_b.x * dot(sub(ray.pos, obj.pos_a), obj.rotate) - obj.radius_b.x;
	a = 4 * pow(obj.radius_a.x, 2) * dot(ray.dir, ray.dir) - pow(a1, 2);
	b = (4 * pow(obj.radius_a.x, 2) * dot(ray.dir, sub(ray.pos, obj.pos_a)) - a1 * a2) * 2;
	c = 4 * pow(obj.radius_a.x, 2) * dot(sub(ray.pos, obj.pos_a), sub(ray.pos, obj.pos_a)) - pow(a2, 2);
	d = sqrt(pow(b, 2) - 4 * a * c);
	a1 = (-b + det) / (2 * a);
	a2 = (-b - det) / (2 * a);
	cmid = add(obj.pos_a, vector_div(vector_mult_x(obj.rotate, det), 2));
	r = sub(obj.collision, cmid);
	obj.normal = sub(r, vector_mult_x(obj.rotate, (1 - (b * b) / (a * a)) * dot(r, obj.rotate)));
	return (obj.normal);
}
*/
/*
float		ellipsoid(register t_obj obj, register t_ray ray)
{
	register t_equ	eq;
	register float	det;

	//obj.radius_b ==> distance between the 2 centers
	//obj.radius_a ==> radius sum
	//radius_a > radius_b
	eq.a = 2 * obj.radius_b.x * dot(ray.dir, obj.rotate);
	eq.b = pow(obj.radius_a.x, 2) + 2 * obj.radius_b.x * dot(sub(ray.pos, obj.pos_a), obj.rotate) - obj.radius_b.x;
	eq.c = 4 * pow(obj.radius_a.x, 2) * dot(ray.dir, ray.dir) - pow(eq.a, 2);
	eq.d = (4 * pow(obj.radius_a.x, 2) * dot(ray.dir, sub(ray.pos, obj.pos_a)) - eq.a * eq.b) * 2;
	eq.e = 4 * pow(obj.radius_a.x, 2) * dot(sub(ray.pos, obj.pos_a), sub(ray.pos, obj.pos_a)) - pow(eq.b, 2);
	det = sqrt(pow(eq.d, 2) - 4 * eq.c * eq.e);
	eq.a = (-eq.d + det) / (2 * eq.c);
	eq.b = (-eq.d - det) / (2 * eq.c);
	if (eq.a > eq.b)
		return (eq.b);
	return (eq.a);
}*/
