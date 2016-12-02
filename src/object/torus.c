/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:33 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/01 14:09:46 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

double			from_zero(register t_roots r)
{
	register int	a;
	register int	b;
	register int	c;
	register int	d;
	register int	i;

	i = 0;
	a = (int)r.x1;
	b = (int)r.x2;
	c = (int)r.x3;
	d = (int)r.x4;
	if (r.x1 <= 0 && r.x2 <= 0 && r.x3 <= 0 && r.x4 <= 0)
		return (-1);
	if (d > 0 || a < 0)
		return (-1);
	while (i < 20000)
	{
		if (i == a && a != 0)
			return (r.x1);
		if (i == b && b != 0)
			return (r.x2);
		if (i == c && c != 0)
			return (r.x3);
		if (i == d && d != 0)
			return (r.x4);
		i++;
	}
	return (-1);
}

inline double	torus(register t_obj obj, register t_ray ray)
{
	register t_equ		c;
	register t_equ		a;
	register t_roots	r;

	a.a = dot(ray.dir, ray.dir);		//m
	a.b = dot(ray.dir, sub(ray.pos, obj.pos_a));		//n
	a.c = dot(sub(ray.pos, obj.pos_a), sub(ray.pos, obj.pos_a));		//o
	a.d = dot(ray.dir, obj.rotate);		//p
	a.e = dot(sub(ray.pos, obj.pos_a), obj.rotate);			//q

	c.a = a.a * a.a;
	c.b = 4 * a.a * a.b;

	c.c = 4 * pow(a.a, 2) + 2 * a.a * a.c - 2 * (pow(obj.radius_a.x, 2) + \
		pow(obj.radius_b.x, 2)) * a.a + 4 * pow(obj.radius_a.x, 2) * \
		(a.d * a.d);


	c.d = 4 * a.b * a.c - 4 * (pow(obj.radius_a.x, 2) + pow(obj.radius_b.x, 2)) * a.b + \
		8 * pow(obj.radius_a.x, 2) * a.d * a.e;


	c.e = pow(a.c, 2) - 2 * (pow(obj.radius_a.x, 2) + pow(obj.radius_b.x, 2)) * a.c \
		+ 4 * pow(obj.radius_a.x, 2) * pow(a.e, 2) + \
		pow((pow(obj.radius_a.x, 2) - pow(obj.radius_b.x, 2)), 2);


	r = solve_quartic_equation(c.a / c.a, c.b / c.a, c.c / c.a, c.d / c.a, c.e / c.a);
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
//	printf("a = %lf | b = %lf | c = %lf | d = %lf | e = %lf\n", a, b, c, d, e);
	r = solve_quartic_equation(a / a, b / a, c / a, d / a, e / a);
//	printf("x1 = %lf | x2 = %lf | x3 = %lf | x4 = %lf\n", r.x1, r.x2, r.x3, r.x4);
	if (r.x1 >= 0 && r.x2 >= 0 && r.x3 >= 0 && r.x4 >= 0)
	{
		if (r.x2 > r.x1 > r.x3 > r.x4)
			return (r.x4);
		if (r.x1 > r.x3 && r.x1 > r.x4)
			return (r.x4);
		return (-1);
	}
	else
		return (-1);
*/
/*	if (r.x4 < 0)
		return (-1);
	if (r.x1 >= 0 && r.x2 >= 0 && r.x3 >= 0 && r.x4 >= 0)
	{
		if (r.x1 > r.x3 && r.x1 > r.x4)
			return (-1);
		return (r.x4);
	}
	else
		return (r.x4);
}
*/
/*	if (r.x1 > 0 && r.x1 <= r.x2 && r.x1 <= r.x3 && r.x1 <= r.x4)
		return (r.x1);
	if (r.x2 > 0 && r.x2 <= r.x1 && r.x2 <= r.x3 && r.x2 <= r.x4)
		return (r.x2);
	if (r.x3 > 0 && r.x3 <= r.x1 && r.x3 <= r.x2 && r.x3 <= r.x4)
		return (r.x3);
	if (r.x4 > 0 && r.x4 <= r.x1 && r.x4 <= r.x2 && r.x4 <= r.x3)
		return (r.x4);
*/
