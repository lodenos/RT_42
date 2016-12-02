/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:26 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/02 13:12:39 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline float	cone(register t_obj obj, register t_ray ray)
{
	register t_equ	cone;
	register float	ta;
	register float	tb;
	register float	det;

	cone.a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z - \
			ray.dir.y * ray.dir.y * obj.angle;
	cone.b = 2.0f * ((ray.pos.x - obj.pos_a.x) * ray.dir.x + \
			(ray.pos.z - obj.pos_a.z) * ray.dir.z - \
			(ray.pos.y - obj.pos_a.y) * ray.dir.y * obj.angle);
	cone.c = ((ray.pos.x - obj.pos_a.x) * (ray.pos.x - obj.pos_a.x)) + \
			((ray.pos.z - obj.pos_a.z) * (ray.pos.z - obj.pos_a.z)) - \
			((ray.pos.y - obj.pos_a.y) * (ray.pos.y - obj.pos_a.y)) * \
			obj.angle - obj.radius_a.x * obj.radius_a.x;
	det = cone.b * cone.b - 4.0f * cone.a * cone.c;
	if (det > 0.0f)
	{
		ta = (-cone.b + sqrtf(det)) / (2.0f * cone.a);
		tb = (-cone.b - sqrtf(det)) / (2.0f * cone.a);
		return (ta > tb) ? tb : ta;
	}
	return (-1.0f);
}
