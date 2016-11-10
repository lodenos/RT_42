/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:27:07 by opettex-          #+#    #+#             */
/*   Updated: 2016/11/09 19:27:08 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

cl_float2   add_vec(cl_float2 a, cl_float2 b)
{
    return ((cl_float2){a.x + b.x, a.y + b.y});
}

cl_float2       div_vec(cl_float2 a, cl_float b)
{
	cl_float2 rlt;
	rlt.x = a.x / b;
	rlt.y = a.y /b;

	return (rlt);
}


float       dot_vec(cl_float2 a, cl_float2 b)
{
    return (a.x * b.x + a.y * b.y);
}

float         fract(float x)
{
    return (x - floorf(x));
}

cl_float2 	fract_2d(cl_float2 v)
{
	cl_float2 ret;

	ret.x = fract(v.x);
	ret.y = fract(v.y);
	return (ret);
}
