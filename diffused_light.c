/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffused_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 00:39:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/14 14:24:34 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	diffused_light(t_obj obj, t_ray ray)
{
	double  a;
	double  b;
	double  c;

	a = sqrt(((ray.ro.x - obj.pos.x) * (ray.ro.x - obj.pos.x)) +    \
			((ray.ro.y - obj.pos.y) * (ray.ro.y - obj.pos.y)) +     \
			((ray.ro.z - obj.pos.z) * (ray.ro.z - obj.pos.z)));
	b = sqrt(((obj.norm.x - obj.pos.x) * (obj.norm.x - obj.pos.x)) +    \
			((obj.norm.y - obj.pos.y) * (obj.norm.y - obj.pos.y)) +     \
			((obj.norm.z - obj.pos.z) * (obj.norm.z - obj.pos.z)));
	c = sqrt(((ray.ro.x - obj.norm.x) * (ray.ro.x - obj.norm.x)) +  \
			((ray.ro.y - obj.norm.y) * (ray.ro.y - obj.norm.y)) +   \
			((ray.ro.z - obj.norm.z) * (ray.ro.z - obj.norm.z)));
	return (1 - cos(asin(((a * a) + (b * b) - (c * c)) / (2 * a * b))));
}
