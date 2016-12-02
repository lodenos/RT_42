/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:14:44 by anespoul          #+#    #+#             */
/*   Updated: 2016/11/14 14:15:21 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

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
}
