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

float				max(float x, float min, float max)
{
	if (x < min)
		return (min);
	return ((x > max) ? max : x);
}

cl_float2			smooth_noise(cl_float2 a, cl_float2 b, float x)
{
	cl_float2	t;

	t = (cl_float2){
		max((x.x - a.x) / (b.x - a.x), 0.0f, 1.0f),
		max((x.y - a.y) / (b.x - a.y), 0.0f, 1.0f),
	};
	return ((t_v2f){t.x * t.x * (3.0f - 2.0f * t.x),
		t.y * t.y * (3.0f - 2.0f * t.y)});
}

float				linear_interpolation(float a, float b, float pc)
{
	return (a * (1.0f - pc) + (b * pc));
}

/*
float				fract(float x)
{
	return (x - floorf(x));
}
*/
  

float 			r(cl_float2 n)
{
	/*float	n2;

	n2 = vect_mult_f((cl_float2){36.26, 73.12}, 354.63);

	return (fract(cosf(vect_mult_vec_f(n2, n)))); */
	return (fract(cosf(dot_vec(n, (cl_float2){36.26f, 73.12f})) * 354.63f));
}                

float			noise(cl_float2 n)
{
	cl_float2	fn;
	cl_float2	sn;
	float	h1;
	float	h2;

	fn = (cl_float2){floorf(n.x), floorf(n.y)};
	sn = smooth_noise(
			(cl_float2){0.0f, 0.0f},
			(cl_float2){1.0f, 1.0f},
			fract_2(n));
	h1 = linear_interpolation(r(fn), r(add_vec(
			(cl_float2){fn.x, fn.y},
			(cl_float2){1.0f, 0.0f})), sn.x);
	h2 = linear_interpolation(r((t_v2f){fn.x, fn.y + 1.0f}),
		r((t_v2f){fn.x + 1.0f, fn.y + 1.0f}), sn.x);
	return (linear_interpolation(h1, h2, sn.y));
}

float 		perlin(cl_float2 n)
{
    float total;

   		total = noise(dot_vec(div_vec(n, 32.0f), 0.5875f)) +
		noise(div_vec(n, 16.0f)) * 0.2f +
		noise(div_vec(n, 0.125f)) * 0.1f +
		noise(div_vec(n, 4.0f)) * 0.05f +
		noise(div_vec(n, 2.0f)) * 0.025f +
		noise(n) * 0.0125f;
 	return (total);
}

/*

t_vector	geo_addv(t_vector a, t_vector b)
{
	return ((t_vector){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_v4f		geo_addv4f(t_v4f a, t_v4f b)
{
	return ((t_v4f){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
}

t_v4d		geo_addv4(t_v4d a, t_v4d b)
{
	return ((t_v4d){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
}

t_v2f		geo_addv2f(t_v2f a, t_v2f b)
{
	return ((t_v2f){a.x + b.x, a.y + b.y});
}

t_v2f		geo_smoothstep(t_v2f a, t_v2f b, t_v2f x)
{
	t_v2f	t;

	t = (t_v2f){
		geo_clamp((x.x - a.x) / (b.x - a.x), 0.0f, 1.0f),
		geo_clamp((x.y - a.y) / (b.x - a.y), 0.0f, 1.0f),
	};
	return ((t_v2f){t.x * t.x * (3.0f - 2.0f * t.x),
		t.y * t.y * (3.0f - 2.0f * t.y)});
}


float	geo_fract(float x)
{
	return (x - floorf(x));
}

t_v2f	geo_fract_v2f(t_v2f v)
{
	return ((t_v2f){geo_fract(v.x), geo_fract(v.y)});
}


float	geo_dotv2f(t_v2f a, t_v2f b)
{
	return (a.x * b.x + a.y * b.y);
}
static float		r(t_v2f n)
{
	return (geo_fract(cosf(geo_dotv2f(n, (t_v2f){36.26f, 73.12f})) * 354.63f));
}

static float		noise(t_v2f n)
{
	t_v2f	fn;
	t_v2f	sn;
	float	h1;
	float	h2;

	fn = (t_v2f){floorf(n.x), floorf(n.y)};
	sn = geo_smoothstep(
			(t_v2f){0.0f, 0.0f},
			(t_v2f){1.0f, 1.0f},
			geo_fract_v2f(n));
	h1 = geo_mix(r(fn), r(geo_addv2f(
			(t_v2f){fn.x, fn.y},
			(t_v2f){1.0f, 0.0f})), sn.x);
	h2 = geo_mix(r((t_v2f){fn.x, fn.y + 1.0f}),
		r((t_v2f){fn.x + 1.0f, fn.y + 1.0f}), sn.x);
	return (geo_mix(h1, h2, sn.y));
}

float				geo_perlin(t_v2f px)
{
	float	total;

	total = noise(geo_v2f_mult(geo_v2f_div(px, 32.0f), 0.5875f)) +
		noise(geo_v2f_div(px, 16.0f)) * 0.2f +
		noise(geo_v2f_mult(px, 0.125f)) * 0.1f +
		noise(geo_v2f_div(px, 4.0f)) * 0.05f +
		noise(geo_v2f_div(px, 2.0f)) * 0.025f +
		noise(px) * 0.0125f;
	return (total);
}


