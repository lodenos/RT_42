/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:47:13 by opettex-          #+#    #+#             */
/*   Updated: 2016/12/15 14:32:47 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

static cl_float2	smooth_noise(cl_float2 a, cl_float2 b, cl_float2 x)
{
	cl_float2		t;

	t = (cl_float2){{
		ft_max((x.x - a.x) / (b.x - a.x), 0.0f, 1.0f),
			ft_max((x.y - a.y) / (b.x - a.y), 0.0f, 1.0f),
	}};
	return ((cl_float2){{t.x * t.x * (3.0f - 2.0f * t.x),
			t.y * t.y * (3.0f - 2.0f * t.y)}});
}

static float		linear_interpolation(float a, float b, float pc)
{
	return (a * (1.0f - pc) + (b * pc));
}

static float		r(cl_float2 n)
{
	return (fract(cosf(dot_vec(n, (cl_float2){{36.26f, 73.12f}})) * 354.63f));
}

float				noise(cl_float2 n)
{
	cl_float2		fn;
	cl_float2		sn;
	float			h1;
	float			h2;

	fn = (cl_float2){{floorf(n.x), floorf(n.y)}};
	sn = smooth_noise(
			(cl_float2){{0.0f, 0.0f}},
			(cl_float2){{1.0f, 1.0f}},
			fract_2d(n));
	h1 = linear_interpolation(r(fn), r(add_vec(
					(cl_float2){{fn.x, fn.y}},
					(cl_float2){{1.0f, 0.0f}})), sn.x);
	h2 = linear_interpolation(r((cl_float2){{fn.x, fn.y + 1.0f}}),
			r((cl_float2){{fn.x + 1.0f, fn.y + 1.0f}}), sn.x);
	return (linear_interpolation(h1, h2, sn.y));
}

float				perlin(cl_float2 n)
{
	float			p;

	p = noise(div_vec(n, 32.0f)) * 0.5875f +
		noise(div_vec(n, 16.0f)) * 0.2f +
		noise(div_vec(n, 4.0f)) * 0.05f +
		noise(div_vec(n, 2.0f)) * 0.025f +
		noise(n) * 0.0125f;
	return ((p));
}
