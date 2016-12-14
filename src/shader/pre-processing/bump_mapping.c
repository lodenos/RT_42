/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 04:15:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/14 19:03:22 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static void	type_damier(t_obj *obj, unsigned int x, unsigned int y,
		unsigned int z)
{
	if (z % 2)
	{
		if ((x % 2 && y % 2) || (!(x % 2) && !(y % 2)))
			obj->color = obj->color;
		else
			obj->color = 0xFF;
	}
	else
	{
		if ((((x % 2 && y % 2) || (!(x % 2) && !(y % 2))) && (obj->type == 16 ||
				obj->type == 2 || obj->type == 4)) || (!((x % 2 && y % 2) ||
				(!(x % 2) && !(y % 2))) && !(obj->type == 16 || obj->type == 2
				|| obj->type == 4)))
			obj->color = obj->color;
		else
			obj->color = 0xFF;
	}
}

void		bump_mapping_sub2(t_obj *obj)
{
	cl_float3	tmp;

	if (obj->type_bump == 5)
	{
		tmp = sub(obj->collision, obj->pos_a);
		obj->color *= varazslat((cl_float2){tmp.x, tmp.y}, time(NULL));
	}
	else if (obj->type_bump == 6)
	{
		tmp = obj->collision;
		obj->color *= line(tmp.y + (time(NULL) * 0.1), 10., 272.);
		obj->color += line(tmp.y + (time(NULL) * 0.1), 10., 272.);
	}
	else if (obj->type_bump == 7)
	{
		tmp = obj->collision;
		obj->color += line(tmp.x + (time(NULL) * 0.1), 10., 272.);
		obj->color *= line(tmp.x + (time(NULL) * 0.1), 10., 272.);
	}
	else if (obj->type_bump == 8)
	{
		tmp = obj->collision;
		obj->color *= mosaic((cl_float2){tmp.x, tmp.y});
	}
}

void		bump_mapping_sub(t_obj *obj)
{
	cl_float3		tmp;
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;

	if (obj->type_bump == 2)
	{
		tmp = sub(obj->collision, obj->pos_a);
		y = (unsigned int)round(tmp.y * 0.1);
		z = (unsigned int)round(tmp.z * 0.1);
		if (obj->type != 8 || obj->collision.x == 0 || obj->pos_a.x >= 0)
			x = (unsigned int)round(tmp.x * 0.1);
		type_damier(obj, x, y, z);
	}
	else if (obj->type_bump == 3)
	{
		tmp = obj->collision;
		obj->color *= perlin((cl_float2){tmp.x, tmp.y});
	}
	else if (obj->type_bump == 4)
	{
		tmp = obj->collision;
		obj->color *= smooth_voronoi((cl_float2){tmp.x, tmp.y});
	}
}

inline void	bump_mapping(t_obj *obj)
{
	cl_float3		tmp;

	if (obj->type_bump == 0)
		return ;
	else if (obj->type_bump == 1)
	{
		tmp = sub(obj->collision, obj->pos_a);
		obj->normal.x -= sinf(tmp.x) * 0.01f;
		obj->normal.y -= sinf(tmp.y) * 0.01f;
		obj->normal.z -= sinf(tmp.z) * 0.01f;
	}
	else
	{
		bump_mapping_sub(obj);
		bump_mapping_sub2(obj);
	}
}
