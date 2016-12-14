/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic_equation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:20:16 by anespoul          #+#    #+#             */
/*   Updated: 2016/12/14 11:37:52 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

struct s_roots			one_root_is_real(register double a, register double b,\
		register double c, register double d)
{
	register double				f;
	register double				g;
	register double				h;
	register t_equ				e;
	register t_roots			roots;

	f = ((3.0f * c / a) - (b * b / (a * a))) / 3.0f;
	g = ((2.0f * (b * b * b) / (a * a * a)) - (9.0f * b * c / (a * a)) + \
			(27.0f * d / a)) / 27.0f;
	h = (g * g / 4.0f) + (f * f * f / 27.0f);
	e.a = -(g / 2.0f) + pow(h, 1.0f / 2.0f);
	if (h < 0.0f)
		e.a = -(g / 2.0f) - pow(ABS(h), 1.0f / 2.0f);
	e.b = pow(e.a, 1.0f / 3.0f);
	if (e.a < 0.0f)
		e.b = -pow(ABS(e.a), 1.0f / 3.0f);
	e.c = -(g / 2.0f) - pow(h, 1.0f / 2.0f);
	if (e.c < 0.0f)
		e.d = -pow(ABS(e.c), 1.0f / 3.0f);
	else
		e.d = pow(e.c, 1.0f / 3.0f);
	roots.x1 = (e.b + e.d) - (b / (3.0f * a));
	roots.complex1.r = -(e.b + e.d) / 2.0f - (b / (3.0f * a));
	roots.complex1.i = (e.b - e.d) * pow(3.0f, 1.0f / 2.0f) / 2.0f;
	return (roots);
}

struct s_roots			all_roots_equal(register double a, register double b,\
		register double c, register double d)
{
	register double				f;
	register double				g;
	register double				h;
	register t_roots			roots;

	f = ((3.0f * c / a) - (b * b / (a * a))) / 3.0f;
	g = ((2.0f * (b * b * b) / (a * a * a)) - (9.0f * b * c / (a * a)) + \
			(27.0f * d / a)) / 27.0f;
	h = (g * g / 4.0f) + (f * f * f / 27.0f);
	roots.x1 = pow((d / a), 1.0f / 3.0f) * -1;
	roots.x2 = roots.x1;
	roots.x3 = roots.x1;
	roots.x4 = 0;
	return (roots);
}

struct s_roots			three_roots_real(register double a, register double b,\
		register double g, register double h)
{
	register double				n;
	register double				p;
	register t_equ				e;
	register t_roots			roots;

	e.a = pow((((g * g) / 4.0f) - h), 1.0f / 2.0f);
	e.b = pow(e.a, 1.0f / 3.0f);
	e.c = acos(-(g / (2.0f * e.a)));
	e.d = -e.b;
	e.e = cos(e.c / 3.0f);
	n = sqrt(3.0f) * sin(e.c / 3.0f);
	p = (b / (3.0f * a)) * -1.0f;
	roots.x1 = 2.0f * e.b * cos(e.c / 3.0f) - (b / (3.0f * a));
	roots.x2 = e.d * (e.e + n) + p;
	roots.x3 = e.d * (e.e - n) + p;
	roots.x4 = 0;
	return (roots);
}

struct s_roots			solve_cubic_equation(register double a, \
		register double b, register double c, register double d)
{
	register double				f;
	register double				g;
	register double				h;
	register t_roots			roots;

	f = ((3.0f * c / a) - ((b * b) / (a * a))) / 3.0f;
	g = (((2.0f * b * b * b) / (a * a * a)) - ((9.0f * b * c) / (a * a)) + \
			((27.0f * d) / a)) / 27.0f;
	h = (g * g / 4.0f) + (f * f * f / 27.0f);
	if (h > 0)
		roots = one_root_is_real(a, b, c, d);
	if (h == 0 && f == 0 && g == 0)
		roots = all_roots_equal(a, b, c, d);
	if (h <= 0)
		roots = three_roots_real(a, b, g, h);
	return (roots);
}
