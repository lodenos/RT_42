/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:50:04 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/28 01:48:27 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    light(t_spt *spt, t_obj *obj, int tmp, t_ray *ray)
{

	int 	index;
	t_obj   tmp_obj;

	t_ray	ray_shadow;

	tmp_obj = obj[tmp];


	ray_shadow.b = tmp_obj.collision;
	ray_shadow.a = spt[0].pos;

	ray_shadow.b = vector_normalize(vector_sub(ray_shadow.b, ray_shadow.a));

	index = intersect(obj, &ray_shadow);

	if ((obj[index].det == -1) || (tmp == index))
	{
		diffused_light(ray, spt[0], tmp_obj);
    	specular_light(ray, spt[0], tmp_obj);
	}
	else
	{
		diffused_light(ray, spt[0], tmp_obj);
		ray->rgba = (t_rgba){ray->rgba.red * 0.1, ray->rgba.green * 0.1, ray->rgba.blue * 0.1, 255};
	}
	
}