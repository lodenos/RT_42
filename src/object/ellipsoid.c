/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <anespoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:14:44 by anespoul          #+#    #+#             */
/*   Updated: 2016/12/15 14:11:04 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

cl_float3	get_ellipsoid_normale(register t_obj *obj, register float det)
{
	(void)det;
	obj->normal = sub(obj->collision, obj->pos_a);
	obj->normal.x = 2.0f * obj->normal.x / (obj->radius_a.x * obj->radius_a.x);
	obj->normal.y = 2.0f * obj->normal.y / (obj->radius_a.y * obj->radius_a.y);
	obj->normal.z = 2.0f * obj->normal.z / (obj->radius_a.z * obj->radius_a.z);
	return (obj->normal);
}

float		get_elli_det(register t_obj obj, register t_equ elli)
{
	register float t1;
	register float t2;

	elli.d = sqrt(elli.d);
	t1 = (-elli.b + elli.d) / (2.0f * elli.a);
	t2 = (-elli.b - elli.d) / (2.0f * elli.a);
	if (t1 <= EPSILON && t2 <= EPSILON)
		return (-1);
	obj.radius_b.x = (t1 <= EPSILON || t2 <= EPSILON);
	elli.e = 0.0f;
	if (t1 <= EPSILON)
		elli.e = t2;
	else
	{
		if (t2 <= EPSILON)
			elli.e = t1;
		else
			elli.e = (t1 < t2) ? t1 : t2;
	}
	if (elli.e < EPSILON)
		return (-1);
	return (elli.e);
}

float		ellipsoid(register t_obj obj, register t_ray ray)
{
	register cl_float3	oc;
	register cl_float3	dir;
	register t_equ		elli;

	oc = sub(ray.pos, obj.pos_a);
	dir = ray.dir;
	normalize(dir);
	elli.a = (dir.x * dir.x) / (obj.radius_a.x * obj.radius_a.x) + \
		(dir.y * dir.y) / (obj.radius_a.y * obj.radius_a.y) + \
		(dir.z * dir.z) / (obj.radius_a.z * obj.radius_a.z);
	elli.b = (2.0f * oc.x * dir.x) / (obj.radius_a.x * obj.radius_a.x) + \
		(2.0f * oc.y * dir.y) / (obj.radius_a.y * obj.radius_a.y) + \
		(2.0f * oc.z * dir.z) / (obj.radius_a.z * obj.radius_a.z);
	elli.c = (oc.x * oc.x) / (obj.radius_a.x * obj.radius_a.x) + \
		(oc.y * oc.y) / (obj.radius_a.y * obj.radius_a.y) + \
		(oc.z * oc.z) / (obj.radius_a.z * obj.radius_a.z) - 1.0f;
	elli.d = ((elli.b * elli.b) - (4.0f * elli.a * elli.c));
	if (elli.d < 0.f || elli.a == 0.f || elli.b == 0.f || elli.c == 0.f)
		return (-1);
	else
		return (get_elli_det(obj, elli));
}
