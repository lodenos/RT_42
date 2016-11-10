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
/*
cl_float2    vect_mult(cl_float2 a, float b)
{
    register cl_float2  tmp;

    tmp.x = a.x * b;
	tmp.y = a.y * b;
    return (tmp);
}

//return (a.x * b.x + a.y * b.y);

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

float    vect_mult_f(cl_float2 a, float b)
{
    register cl_float2  tmp;

    tmp.x = a.x * b;
	tmp.y = a.y * b;
    return (tmp);
}

float    vect_mult(cl_float2 a, cl_float2 b)
{
    register cl_float2  tmp;

    tmp.x = a.x * b;
	tmp.y = a.y * b;
    return (tmp);
}

float 	vect_mult_vec_f(cl_float2 a, cl_float2 b)
{
	float x;
	float y;
	float r;

	x = (a.x * b.x);
	y = (a.y * b.y);
	r = (x + y);

	return (r);
}

float   vect_mult_f(cl_float2 a, float b)
{
    float x;  
    float r;     

    x = (a.x * b);
	y = (a.y * b);
	r = (x + y);

    return (r);
}
*/

cl_float2   add_vec(cl_float2 a, cl_float2 b)
{
    return ((cl_float2){a.x + b.x, a.y + b.y, a.z + b.z});
}

float       div_vec(cl_float2 a, cl_float2 b)
{
    return ((a.x / b.x) +  (a.y / b.y));
}


float       dot_vec(cl_float2 a, cl_float2 b)
{
    return (a.x * b.x + a.y * b.y);
}

float         fract(float x)
{
    return (x - floorf(x));
}

