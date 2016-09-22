/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffused_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 00:39:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 13:09:17 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	diffused_light(t_obj obj, t_ray ray, t_spt spt)
{
	double  a;
	double  b;
	double  c;
	(void)ray;
	
	a = sqrt(((spt.pos.x - obj.pos.x) * (spt.pos.x - obj.pos.x)) +    \
			((spt.pos.y - obj.pos.y) * (spt.pos.y - obj.pos.y)) +     \
			((spt.pos.z - obj.pos.z) * (spt.pos.z - obj.pos.z)));
	b = sqrt(((obj.norm.x - obj.pos.x) * (obj.norm.x - obj.pos.x)) +    \
			((obj.norm.y - obj.pos.y) * (obj.norm.y - obj.pos.y)) +     \
			((obj.norm.z - obj.pos.z) * (obj.norm.z - obj.pos.z)));
	c = sqrt(((spt.pos.x - obj.norm.x) * (spt.pos.x - obj.norm.x)) +  \
			((spt.pos.y - obj.norm.y) * (spt.pos.y - obj.norm.y)) +   \
			((spt.pos.z - obj.norm.z) * (spt.pos.z - obj.norm.z)));
	return (1 - cos(asin(((a * a) + (b * b) - (c * c)) / (2 * a * b))));
}
