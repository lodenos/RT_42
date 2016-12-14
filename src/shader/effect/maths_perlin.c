/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_perlin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 21:19:09 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/14 14:19:50 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

cl_float2	add_vec(cl_float2 a, cl_float2 b)
{
	return ((cl_float2){a.x + b.x, a.y + b.y});
}

cl_float2	div_vec(cl_float2 a, cl_float b)
{
	cl_float2	rlt;

	rlt.x = a.x / b;
	rlt.y = a.y / b;
	return (rlt);
}

cl_float2	dot_vec_f(cl_float2 a, cl_float b)
{
	cl_float2	rlt;

	rlt.x = a.x * b;
	rlt.y = a.y * b;
	return (rlt);
}

float		dot_vec(cl_float2 a, cl_float2 b)
{
	return (a.x * b.x + a.y * b.y);
}

float		ft_max(float x, float min, float max)
{
	if (x < min)
		return (min);
	return ((x > max) ? max : x);
}
