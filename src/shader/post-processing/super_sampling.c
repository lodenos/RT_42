/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_sampling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 21:08:14 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:34:03 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

void	super_sampling_sub(t_env *e, t_ray *ray, cl_float2 pos, cl_float3 *rgb)
{
	camera(e->scn.cam, ray, pos.x, pos.y);
	run_raytracing(e, e->obj, ray);
	rgb->x += (float)(((unsigned char)(ray->color >> 24)));
	rgb->y += (float)(((unsigned char)(ray->color >> 16)));
	rgb->z += (float)(((unsigned char)(ray->color >> 8)));
}

void	super_sampling(t_env *e, t_ray *ray, cl_float2 pos, size_t resolution)
{
	t_ssamp		s;

	s.i = 0;
	s.x = pos.x;
	s.div = 1.0 / resolution;
	s.max = resolution * resolution;
	s.rgb = (cl_float3){0, 0, 0};
	if (resolution == 0)
		ft_putstr_err("ERROR: supersampling -> resolution == 0", 1);
	while (s.i < resolution)
	{
		s.j = 0;
		while (s.j < resolution)
		{
			super_sampling_sub(e, ray, pos, &s.rgb);
			pos.x += s.div;
			++s.j;
		}
		pos.x = s.x;
		pos.y += s.div;
		++s.i;
	}
	ray->color = (unsigned int)((unsigned char)(s.rgb.x / (float)s.max)) << 24 |
		(unsigned int)((unsigned char)(s.rgb.y / (float)s.max)) << 16 |
		(unsigned int)((unsigned char)(s.rgb.z / (float)s.max)) << 8 | 0xFF;
}
