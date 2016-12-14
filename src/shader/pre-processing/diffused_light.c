/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffused_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 04:50:32 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/14 11:46:48 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void	diffused_light(t_ray *ray, register t_spt spt, register t_obj obj)
{
	register float	z;

	obj.diffuse = 1;
	z = -(dot(normalize(sub(obj.collision, spt.pos)), obj.normal)
			* obj.diffuse);
	ray->color = (unsigned int)limit((((unsigned char)(ray->color >> 24) +
					(unsigned char)(spt.color >> 24)) / 2) * z) << 24 |
		(unsigned int)limit((((unsigned char)(ray->color >> 16) +
						(unsigned char)(spt.color >> 16)) / 2) * z) << 16 |
		(unsigned int)limit((((unsigned char)(ray->color >> 8) +
						(unsigned char)(spt.color >> 8)) / 2) * z) << 8 |
		(unsigned int)limit((((unsigned char)ray->color +
						(unsigned char)spt.color) / 2) * z);
}
