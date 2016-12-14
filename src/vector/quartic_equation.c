/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:16:45 by anespoul          #+#    #+#             */
/*   Updated: 2016/12/14 11:05:38 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

struct s_roots	get_complex_roots(register t_roots r, register double a,\
		register double b, register double g)
{
	register double		r1;
	register double		x;
	register double		y;
	register double		s;

	r1 = sqrt(pow(r.complex1.r, 2) + pow(r.complex1.i, 2));
	y = sqrt((r1 - r.complex1.r) / 2);
	x = r.complex1.i / (2 * y);
	r1 = -g / (8 * (x * x + y * y));
	s = b / (4 * a);
	r.x1 = (x + y) + (x - y) + r1 - s;
	r.x2 = (x + y) - (x - y) - r1 - s;
	r.x3 = -(x + y) + (x - y) - r1 - s;
	r.x4 = -(x + y) - (x - y) + r1 - s;
	return (r);
}

struct s_roots	get_roots(register double x1, register double x2,\
		register t_equ a, register double g)
{
	register double		p;
	register double		q;
	register double		r1;
	register double		s;
	register t_roots	r;

	p = sqrt(ABS(x1));
	q = sqrt(ABS(x2));
	r1 = -g / (8.0f * p * q);
	s = a.b / (4.0f * a.a);
	r.x1 = p + q + r1 - s;
	r.x2 = p - q - r1 - s;
	r.x3 = -p + q - r1 - s;
	r.x4 = -p - q + r1 - s;
	return (r);
}

struct s_roots	solve_quartic_equation(register t_equ a)
{
	register double		f;
	register double		g;
	register double		h;
	register t_roots	roots;

	f = a.c - (3.0f * a.b * a.b / 8.0f);
	g = a.d + (a.b * a.b * a.b / 8.0f) - (a.b * a.c / 2.0f);
	h = a.e - (3.0f * a.b * a.b * a.b * a.b / 256.0f) + \
		(a.b * a.b * a.c / 16.0f) - (a.b * a.d / 4.0f);
	roots = solve_cubic_equation(1.0f, f / 2.0f, (f * f - 4.0f * h) / 16.0f, \
			-(g * g) / 64.0f);
	if (roots.x4 == 1)
		return (get_complex_roots(roots, a.a, a.b, g));
	else if ((int)roots.x2 == 0)
		return (get_roots(roots.x1, roots.x3, a, g));
	else if ((int)roots.x3 == 0)
		return (get_roots(roots.x1, roots.x2, a, g));
	else
		return (get_roots(roots.x2, roots.x3, a, g));
	return (roots);
}
