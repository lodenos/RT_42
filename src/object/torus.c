/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:33 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/14 11:33:51 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"


inline float	torus(register t_obj obj, register t_ray ray)
{
	register t_equ		c;
	register t_equ		a;
	register t_roots	r;

	obj.rotate = normalize(obj.rotate);
	ray.dir = normalize(ray.dir);

	a.a = dot(ray.dir, ray.dir);		//m
	a.b = dot(ray.dir, sub(ray.pos, obj.pos_a));		//n
	a.c = dot(sub(ray.pos, obj.pos_a), sub(ray.pos, obj.pos_a));		//o
	a.d = dot(ray.dir, obj.rotate);		//p
	a.e = dot(sub(ray.pos, obj.pos_a), obj.rotate);			//q

	c.a = a.a * a.a;
	c.b = (4 * a.a * a.b) / c.a;

	c.c = (4 * pow(a.a, 2) + 2 * a.a * a.c - 2 * (pow(obj.radius_a.x, 2) + \
		pow(obj.radius_b.x, 2)) * a.a + 4 * pow(obj.radius_a.x, 2) * \
		(a.d * a.d)) / c.a;


	c.d = (4 * a.b * a.c - 4 * (pow(obj.radius_a.x, 2) + pow(obj.radius_b.x, 2)) * a.b + \
		8 * pow(obj.radius_a.x, 2) * a.d * a.e) / c.a;


	c.e = (pow(a.c, 2) - 2 * (pow(obj.radius_a.x, 2) + pow(obj.radius_b.x, 2)) * a.c \
		+ 4 * pow(obj.radius_a.x, 2) * pow(a.e, 2) + \
		pow((pow(obj.radius_a.x, 2) - pow(obj.radius_b.x, 2)), 2)) / c.a;
	c.a = c.a / c.a;

	r = solve_quartic_equation(c);
//	printf("x1 = %lf | x2 = %lf | x3 = %lf | x4 = %lf\n", r.x1, r.x2, r.x3, r.x4);
	if (r.x4 < 0)
		return (-1);
	else
		return (r.x4);
}

/*
inline double	torus(register t_obj obj, register t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	e;
	double	g;
	double	h;
	double	i;
	double	j;
	double	k;
	double	l;
	t_roots	r;

	g = 4 * pow(obj.radius_a.x, 2) * (ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y);
	h = 8 * pow(obj.radius_a.x, 2) * (ray.pos.x * ray.dir.x + ray.dir.y * ray.pos.y);
	i = 4 * pow(obj.radius_a.x, 2) * (ray.pos.x * ray.pos.x + ray.pos.y * ray.pos.y);
	j = dot(ray.dir, ray.dir);
	k = 2 * dot(ray.dir, ray.pos);
	l = dot(ray.pos, ray.pos) + (pow(obj.radius_a.x, 2) - pow(obj.radius_b.x, 2));

	a = j * j;
	b = 2 * j * k;
	c = 2 * j * l + k * k - g;
	d = 2 * k * l - h;
	e = l * l - i;

	a = 1;
	b = -142.975423;
	c = 7581.166356;
	d = -176784.218216;
	e = 1530625;

	r = solve_quartic_equation(a / a, b / a, c / a, d / a, e / a);
	if (r.x4 < EPSILON)
		return (-1);
	if (r.x1 >= 0 && r.x2 >= 0 && r.x3 >= 0 && r.x4 >= 0)
	{
		if (r.x1 > r.x3 && r.x1 > r.x4)
		{
			return (r.x4);
		}
		if (r.x2 > r.x4)
		{
			return (r.x4);
		}
		return (-1);
	}
	else
		return (-1);
}*/
