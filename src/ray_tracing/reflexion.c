/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:03:46 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/14 14:30:20 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void	reflexion(t_env *e, t_ray *ray, t_obj obj_tmp, size_t id)
{
	int				i;
	unsigned int	color;
	float			det;

	i = -1;
	while (++i < 5)
	{
		ray->pos = obj_tmp.collision;
		ray->dir = sub(ray->dir, vector_mult_x(vector_mult_x(obj_tmp.normal,
						dot(obj_tmp.normal, ray->dir)), 2));
		det = check_object(e->obj, *ray, &id, id);
		if (det == -1)
			return ;
		det += 0.01;
		color = ray->color;
		obj_tmp = e->obj[id];
		obj_tmp.collision = coordinates_collision(ray->pos, ray->dir, det);
		get_normal_object(&obj_tmp, *ray, det);
		bump_mapping(&obj_tmp);
		light(e, id, obj_tmp, ray);
		if (obj_tmp.reflexion == 0)
			return ;
	}
	if (obj_tmp.reflexion > 0)
		ray->color = 0x0;
}
