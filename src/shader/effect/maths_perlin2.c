/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_perlin2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:15:06 by anespoul          #+#    #+#             */
/*   Updated: 2016/12/14 14:16:50 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

float		fract(float x)
{
	return (x - floorf(x));
}

cl_float2	fract_2d(cl_float2 v)
{
	cl_float2	ret;

	ret.x = fract(v.x);
	ret.y = fract(v.y);
	return (ret);
}

cl_float2	fract_vec(cl_float2 x)
{
	return ((cl_float2){x.x - floorf(x.x), x.y - floorf(x.y)});
}

cl_float2	sub_vec(cl_float2 a, cl_float2 b)
{
	return ((cl_float2){a.x - b.x, a.y - b.y});
}

cl_float2	sub_vec_lol(cl_float2 a, cl_float b)
{
	return ((cl_float2){a.x - b, a.y - b});
}
