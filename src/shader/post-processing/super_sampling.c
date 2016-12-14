/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_sampling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 21:08:14 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/12 13:11:55 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void	super_sampling(t_env *e, t_ray *ray, cl_float2 pos, size_t resolution)
{
	size_t	i;
	size_t	j;
	float	x;
	float	div;
	size_t	max;
	float	red;
	float	green;
	float	blue;

	i = 0;
	x = pos.x;
	div = 1.0 / resolution;
	max = resolution * resolution;
	red = 0;
	green = 0;
	blue = 0;
	if (resolution == 0)
		ft_putstr_err("ERROR: supersampling -> resolution == 0", 1);
	while (i < resolution)
	{
		j = 0;
		while (j < resolution)
		{
			camera(e->scn.cam, ray, pos.x, pos.y);
			run_raytracing(e, e->obj, ray);
			red += (float)(((unsigned char)(ray->color >> 24)));
			green += (float)(((unsigned char)(ray->color >> 16)));
			blue += (float)(((unsigned char)(ray->color >> 8)));
			pos.x += div;
			++j;
		}
		pos.x = x;
		pos.y += div;
		++i;
	}
	ray->color = (unsigned int)((unsigned char)(red / (float)max)) << 24 |
		(unsigned int)((unsigned char)(green / (float)max)) << 16 |
		(unsigned int)((unsigned char)(blue / (float)max)) << 8 | 0xFF;
}
