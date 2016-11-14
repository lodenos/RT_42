/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 04:15:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/28 04:30:36 by glodenos         ###   ########.fr       */
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
        if ((((x % 2 && y % 2) || (!(x % 2) && !(y % 2))) && (obj->type == 1
               || obj->type == 4)) || (!((x % 2 && y % 2) || (!(x % 2) &&
                !(y % 2))) && !(obj->type == 1 || obj->type == 4)))
            obj->color = obj->color;
        else
			obj->color = 0xFF;
	}
}

inline void bump_mapping(t_obj *obj)
{
	cl_float3   tmp;
	unsigned int           x;
	unsigned int           y;
	unsigned int           z;

	if (obj->type_bump == 0)// || obj->type_bump == 2)
		return ;
	else if (obj->type_bump == 1)
	{
		tmp = sub(obj->collision, obj->pos);
		obj->normal.x -= sinf(tmp.x) * 0.01f;
		obj->normal.y -= sinf(tmp.y) * 0.01f;
		obj->normal.z -= sinf(tmp.z) * 0.01f;
	}
	else if (obj->type_bump == 2)
	{
		tmp = sub(obj->collision, obj->pos);
		x = (unsigned int) round(tmp.x * 0.1);
		y = (unsigned int) round(tmp.y * 0.1);
		z = (unsigned int) round(tmp.z * 0.1);
		type_damier(obj, x, y, z);
	}
}
