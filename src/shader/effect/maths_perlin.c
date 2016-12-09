/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_perlin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 21:19:09 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/09 15:17:56 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

cl_float2   add_vec(cl_float2 a, cl_float2 b)
{
	return ((cl_float2){a.x + b.x, a.y + b.y});
}

cl_float2   div_vec(cl_float2 a, cl_float b)
{
	cl_float2	rlt;

	rlt.x = a.x / b;
	rlt.y = a.y /b;
	return (rlt);
}

cl_float2   dot_vec_f(cl_float2 a, cl_float b)
{
	cl_float2	rlt;

	rlt.x = a.x * b;
	rlt.y = a.y *b;
	return (rlt);
}

float       dot_vec(cl_float2 a, cl_float2 b)
{
    return (a.x * b.x + a.y * b.y);
}

float       fract(float x)
{
    return (x - floorf(x));
}

cl_float2 	fract_2d(cl_float2 v)
{
	cl_float2	ret;

	ret.x = fract(v.x);
	ret.y = fract(v.y);
	return (ret);
}

cl_float2   fract_vec(cl_float2 x)
{
	return ((cl_float2){x.x - floorf(x.x), x.y - floorf(x.y)});
}

cl_float2   sub_vec(cl_float2 a, cl_float2 b)
{
	return ((cl_float2){a.x - b.x, a.y - b.y});
}

cl_float2   sub_vec_lol(cl_float2 a, cl_float b)
{
	return ((cl_float2){a.x - b, a.y - b});
}
