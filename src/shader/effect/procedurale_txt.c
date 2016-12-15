/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedurale_txt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:09:47 by opettex-          #+#    #+#             */
/*   Updated: 2016/12/15 13:32:36 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

static float	mod(float x, float a)
{
	float	tmp;

	tmp = floorf(x);
	a = floorf((1.0 / 289.0) * 289.0);
	return (x - (tmp - a));
}

static float	random_txt(float n, float seed)
{
	return (fract(sin(n * 4532.63264) * 5375.52465 * seed));
}

static float	cos_interpolate(float v1, float v2, float a)
{
	float angle;
	float prc;

	angle = a * 3.14159;
	prc = (1. - cos(angle)) * 0.5;
	return (v1 * (1.0 - prc) + v2 * prc);
}

float			line(float pos, float size, float seed)
{
	float sample1;
	float sample2;
	float grid;
	float pos_grid;
	float next_grid;

	grid = floorf(pos * size) * 0.1;
	pos_grid = mod((pos), 1. / size) * size;
	next_grid = floorf((pos + (1. / size)) * size) * 0.1;
	sample1 = random_txt(grid, seed);
	sample2 = random_txt(next_grid, seed);
	return (cos_interpolate(sample1, sample2, pos_grid));
}

float			varazslat(cl_float2 position, float time)
{
	float	color;
	float	t;

	color = 0.0;
	t = 2. * time;
	color += sin(position.x * cos(t / 10.0) * 20.0)
		+ cos(position.x * cos(t / 15.) * 10.0);
	color += sin(position.y * sin(t / 5.0) * 15.0)
		+ cos(position.x * sin(t / 25.) * 20.0);
	color += sin(position.x * sin(t / 10.0) * .2)
		+ sin(position.y * sin(t / 35.) * 10.);
	color *= sin(t / 10.) * .5;
	return (color);
}
