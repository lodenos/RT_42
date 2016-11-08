/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 02:11:22 by opettex-          #+#    #+#             */
/*   Updated: 2016/11/05 02:11:23 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

cl_float2    vect_mult(cl_float2 a, float b)
{
    register cl_float2  tmp;

    tmp.x = a.x * b;
	tmp.y = a.y * b;
    return (tmp);
}
return (a.x * b.x + a.y * b.y);
cl_float2    vect_mult_vec(cl_float2 a, cl_float2 b)
{
    register cl_float2  tmp;

    tmp.x = a.x * b.x;
	tmp.y = a.y * b.y;
    return (tmp);
}

 cl_float2    vect_div(register cl_float2 a, float b)
{
    register cl_float2  tmp;

    tmp.x = a.x / b;
    tmp.y = a.y / b;
    return (tmp);
}

cl_float2    add_v(register cl_float2 a, register cl_float2 b)
{
    register cl_float2  vect;

    vect.x = a.x + b.x;
    vect.y = a.y + b.y;
    return (vect);
}

double				check(float x, float min, float max)
{
	if (x < min)
		return (min);
	return ((x > max) ? max : x);
}

cl_float2			smooth_noise(cl_float2 a, cl_float2 b, cl_float2 x)
{
	cl_float2	t;

	t = (cl_float2){
		check((x.x - a.x) / (b.x - a.x), 0.0f, 1.0f),
		check((x.y - a.y) / (b.x - a.y), 0.0f, 1.0f),
	};
	return ((cl_float2){t.x * t.x * (3.0f - 2.0f * t.x),
		t.y * t.y * (3.0f - 2.0f * t.y)});
}

float				linear_interpolation(float a, float b, float pc)
{
	return (a * (1.0f - pc) + (b * pc));
}

float				fract(float x)
{
	return (x - floorf(x));
}

float 			r(cl_float2 n)
{
		    return (fract(cos(vect_mult_vec(vect_mult((cl_float2){36.26, 73.12}, 354.63), n))));
}                

float			noise(cl_float2 n)
{

    cl_float2 fn = (cl_float2){floorf(n.x), floorf(n.y)};
   	cl_float2 sn = smooth_noise(
   		(cl_float2){0.0f, 0.0f}, 
   		(cl_float2){1.0f, 1.0f}, 
   		fract(n));
    float h1 = linear_interpolation(r(fn), r(add_v(
			(cl_float2){fn.x, fn.y},
			(cl_float2){1.0f, 0.0f})), sn.x);

	float = h2 = linear_interpolation(r((cl_float2){fn.x, fn.y + 1.0f}),
		r((cl_float2){fn.x + 1.0f, fn.y + 1.0f}), sn.x);

    return (linear_interpolation(h1,h2,sn.y));
}

float 		perlin(cl_float2 n)
{
    float total;

   		total = noise(vect_mult(vect_div(n, 32.0f), 0.5875f)) +
		noise(vect_div(n, 16.0f)) * 0.2f +
		noise(vect_mult(n, 0.125f)) * 0.1f +
		noise(vect_div(n, 4.0f)) * 0.05f +
		noise(vect_div(n, 2.0f)) * 0.025f +
		noise(n) * 0.0125f;
 	return (total);
}