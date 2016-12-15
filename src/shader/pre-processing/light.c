/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:50:04 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 14:54:31 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

void	light_sub(cl_float3 rgb, t_env *e, t_ray *ray, float z)
{
	ray->color = (unsigned int)(unsigned char)(rgb.x / e->scn.n_spt) << 24 |
		(unsigned int)(unsigned char)(rgb.y / e->scn.n_spt) << 16 |
		(unsigned int)(unsigned char)(rgb.z / e->scn.n_spt) << 8 | 0xFF;
	if (z > 0.0f)
		ray->color = limit((float)(unsigned char)(ray->color >> 24) +
				(float)(unsigned char)(e->spt->color >> 24) * z) << 24 |
			limit((float)(unsigned char)(ray->color >> 16) +
					(float)(unsigned char)(e->spt->color >> 16) * z) << 16 |
			limit((float)(unsigned char)(ray->color >> 8) +
					(float)(unsigned char)(e->spt->color >> 8) * z) << 8 | 0xFF;
}

void	light_sub2(cl_float3 *math, t_spt spt, t_obj obj_tmp, t_ray *ray)
{
	diffused_light(ray, spt, obj_tmp);
	math->y = specular_light(spt, obj_tmp);
	if (math->y >= math->z)
		math->z = math->y;
}

void	light_sub3(cl_float3 *rgb, unsigned int color)
{
	rgb->x += (float)(unsigned char)(color >> 24);
	rgb->y += (float)(unsigned char)(color >> 16);
	rgb->z += (float)(unsigned char)(color >> 8);
}

void	light(t_env *e, size_t id, t_obj obj_tmp, t_ray *ray)
{
	size_t		i;
	size_t		index;
	t_ray		ray_spot;
	cl_float3	rgb;
	cl_float3	math;

	i = 0;
	rgb = (cl_float3){{0.0f, 0.0f, 0.0f}};
	math = (cl_float3){{0.0f, 0.0f, 0.0f}};
	while (e->spt[i].end)
	{
		index = 0;
		ray->color = obj_tmp.color;
		ray_spot.pos = e->spt[i].pos;
		ray_spot.dir = normalize(sub(obj_tmp.collision, ray_spot.pos));
		math.x = check_object(e->obj, ray_spot, &index, NO_MASK);
		if ((math.x == -1) || (id == index))
			light_sub2(&math, e->spt[i], obj_tmp, ray);
		else
			ray->color = 0x0;
		light_sub3(&rgb, ray->color);
		++i;
	}
	light_sub(rgb, e, ray, math.z);
}
