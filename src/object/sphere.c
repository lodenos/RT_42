/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:11 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/09 11:50:20 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline float		sphere(register t_obj obj, register t_ray ray)
{
	register float	b;
	register float	c;

	ray.pos = sub(ray.pos, obj.pos_a);
	b = dot(ray.pos, ray.dir);
	c = b * b - (dot(ray.pos, ray.pos) - obj.radius_a.x * obj.radius_a.x);
	if (c < 0)
		return (-1);
	else
	{
		c = sqrtf(c);
		return ((-b - c > 0) ? -b - c : -b + c);
	}
}
