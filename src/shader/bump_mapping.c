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

inline void bump_mapping(t_obj *obj)
{
	cl_float3   tmp;
	unsigned int           x;
	unsigned int           y;
	unsigned int           z;

	if (obj->type_bump == 0)
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
		tmp = obj->collision;
		x = round(tmp.x * 0.4 + 0.0001);
		y = round(tmp.y * 0.4 + 0.0001);
		z = round(tmp.z * 0.4 + 0.0001);
		if ( z % 2)
		{
			if ((x % 2 && y % 2) || (!(x % 2) && !(y % 2))) 
				obj->color = 0xFFFFFFFF;
			else
				obj->color = 0xFF;
		} 
		else
		{ 
			if ((x % 2 && y % 2) || (!(x % 2) && !(y % 2))) 
				obj->color = 0xFF;
			else 
				obj->color = 0xFFFFFFFF;
		}
	}
}
