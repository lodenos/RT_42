/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic_equation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:20:16 by anespoul          #+#    #+#             */
/*   Updated: 2016/12/13 12:11:34 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

struct s_roots			one_root_is_real(register double a, register double b,\
		register double c, register double d)
{
	register double				f;
	register double				g;
	register double				h;
	register double				r;
	register double				s;
	register double				t;
	register double				u;
	register t_roots			roots;

	f = ((3.0f * c / a) - (b * b / (a * a))) / 3.0f;
	g = ((2.0f * (b * b * b) / (a * a * a)) - (9.0f * b * c / (a * a)) + (27.0f * d / a)) / 27.0f;
	h = (g * g / 4.0f) + (f * f * f / 27.0f);
	
	if (h < 0.0f)
		r = -(g / 2.0f) - pow(ABS(h), 1.0f / 2.0f);
	else
		r = -(g / 2.0f) + pow(h, 1.0f / 2.0f);

	if (r < 0.0f)
		s = -pow(ABS(r), 1.0f / 3.0f);
	else
		s = pow(r, 1.0f / 3.0f);

	t = -(g / 2.0f) - pow(h, 1.0f / 2.0f);
	if (t < 0.0f)
		u = -pow(ABS(t), 1.0f / 3.0f);
	else
		u = pow(t, 1.0f / 3.0f);

//	printf("s == %lf | u == %lf | b == %lf | a == %lf\n", s, u, b, a);
	roots.x1 = (s + u) - (b / (3.0f * a));
//	printf("x1 == %lf\n", roots.x1);
	roots.x2 = 0;
	roots.x3 = 0;
	roots.complex1.r = -(s + u) / 2.0f - (b / (3.0f * a));
	roots.complex1.i = (s - u) * pow(3.0f, 1.0f / 2.0f) / 2.0f;
	roots.x4 = 1;
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
	g = ((2.0f * (b * b * b) / (a * a * a)) - (9.0f * b * c / (a * a)) + (27.0f * d / a)) / 27.0f;
	h = (g * g / 4.0f) + (f * f * f / 27.0f);
	roots.x1 = pow((d / a), 1.0f / 3.0f ) * -1;
	roots.x2 = roots.x1;
	roots.x3 = roots.x1;
	roots.x4 = 0;
	return (roots);
}

struct s_roots			three_roots_real(register double a, register double b,\
		register double g, register double h)
{
	register double				i;
	register double				j;
	register double				k;
	register double				l;
	register double				m;
	register double				n;
	register double				p;
	register t_roots			roots;

	i = pow((((g * g) / 4.0f) - h), 1.0f / 2.0f);
	j = pow(i, 1.0f / 3.0f);
	k = acos(-(g / (2.0f * i)));
	l = -j;
	m = cos(k / 3.0f);
	n = sqrt(3.0f) * sin(k / 3.0f);
	p = (b / (3.0f * a)) * -1.0f;

	roots.x1 = 2.0f * j * cos(k / 3.0f) - (b / (3.0f * a));
	roots.x2 = l * (m + n) + p;
	roots.x3 = l * (m - n) + p;
	roots.x4 = 0;
	return (roots);
}

struct s_roots			solve_cubic_equation(register double a, register double b,\
		register double c, register double d)
{
	register double				f;
	register double				g;
	register double				h;
	register t_roots			roots;

	f = ((3.0f * c / a) - ((b * b) / (a * a))) / 3.0f;
	g = (((2.0f * b * b * b) / (a * a * a)) - ((9.0f * b * c) / (a * a)) + ((27.0f * d) / a)) / 27.0f;
	h = (g * g / 4.0f) + (f * f * f / 27.0f);

//	printf("f == %lf | g == %lf | h == %lf\n", f, g, h);
	if (h > 0)
		roots = one_root_is_real(a, b, c, d);
	if (h == 0 && f == 0 && g == 0)
		roots = all_roots_equal(a, b, c, d);
	if (h <= 0)
		roots = three_roots_real(a, b, g, h);
	return (roots);
}


