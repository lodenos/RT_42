/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voronoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 21:09:21 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/14 14:30:59 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

cl_float2		random2(cl_float2 c)
{
	float		j;
	cl_float2	r;

	j = 4906.0 * sin(dot_vec(c, (cl_float2){200.7, 5.8}));
	r.x = fract(512.0 * j);
	j *= 0.125;
	r.y = fract(512.0 * j);
	return (sub_vec_lol(r, 0.5));
}

float			smooth_voronoi(cl_float2 x)
{
	t_voronoi	v;
	float		d;
	float		res;
	int			j;
	int			i;

	j = -1;
	res = 0.0;
	v.f = fract_vec(x);
	v.p = (cl_float2){floor(x.x), floor(x.y)};
	while (j <= 1)
	{
		i = -1;
		while (i <= 1)
		{
			v.b = ((cl_float2){i, j});
			v.lol = add_vec(v.p, v.b);
			v.r = add_vec(sub_vec(v.b, v.f), random2(v.lol));
			d = dot_vec(v.r, v.r);
			res += 1.0 / pow(d, 8.0);
			++i;
		}
		++j;
	}
	return (pow(1.0 / res, 1.0 / 8.0));
}
