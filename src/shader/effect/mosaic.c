/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosaic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:15:10 by opettex-          #+#    #+#             */
/*   Updated: 2016/12/15 14:30:10 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

cl_float2		dot_vec2(cl_float2 a, cl_float2 b)
{
	cl_float2	ret;

	ret.x = a.x * b.x;
	ret.y = a.y * b.y;
	return ((cl_float2){{ret.x, ret.y}});
}

cl_float2		dot_vec_f2(cl_float2 a, cl_float b)
{
	cl_float2 ret;

	ret.x = a.x * b;
	ret.y = a.y * b;
	return (ret);
}

static float	hash(float n)
{
	return (fract(sin(n) * 43758.5453));
}

float			mosaic(cl_float2 x)
{
	cl_float2	p;
	cl_float2	f;
	cl_float	n;
	cl_float	b;
	cl_float2	ret;

	b = 3.0f - 2.0f;
	f = fract_2d(x);
	p = (cl_float2){{floorf(x.x), floorf(x.y)}};
	ret.x = f.x * f.x;
	ret.y = f.y * f.y;
	f = dot_vec2(dot_vec2(f, ret), dot_vec_f2(f, b));
	n = p.x + p.y * 57.0;
	return (ft_max(ft_max(hash(n + 0.0), hash(n + 1.0), f.x),
				ft_max(hash(n + 57.0), hash(n + 58.0), f.x), f.y));
}
