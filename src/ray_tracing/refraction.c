/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:04:04 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:31:11 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

void	refraction(t_env *e, t_ray *ray, t_obj obj_tmp, size_t id)
{
	unsigned int	color;
	float			det;

	ray->pos = obj_tmp.collision;
	ray->dir = rayon_refracte(obj_tmp.normal, ray->dir, 1, -1.5);
	det = check_object(e->obj, *ray, &id, id);
	if (det == -1)
		return ;
	det += 0.01;
	obj_tmp = e->obj[id];
	obj_tmp.collision = coordinates_collision(ray->pos, ray->dir, det);
	ray->color = (unsigned int)limit((unsigned char)(ray->color >> 24) +
			(unsigned char)(ray->color >> 24) / 2) << 24 |
			(unsigned int)limit((unsigned char)(ray->color >> 16) +
			(unsigned char)(ray->color >> 16) / 2) << 16 |
			(unsigned int)limit((unsigned char)(ray->color >> 8) +
			(unsigned char)(ray->color >> 8) / 2) << 8 |
			(unsigned int)limit((unsigned char)(ray->color) +
			(unsigned char)(ray->color) / 2);
	color = ray->color;
	get_normal_object(&obj_tmp, *ray, det);
	bump_mapping(&obj_tmp);
	light(e, id, obj_tmp, ray);
}
