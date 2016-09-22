/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 11:53:16 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/21 13:49:31 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double  cylinder(t_obj obj, t_ray ray)
{
	t_evo evo;

	evo.a = ray.rd.x * ray.rd.x + ray.rd.z * ray.rd.z;

	evo.b = 2 * ((ray.ro.x - obj.pos.x) * ray.rd.x \
			+ (ray.ro.z - obj.pos.z) * ray.rd.z);

	evo.c = (ray.ro.x - obj.pos.x) * (ray.ro.x - obj.pos.x) \
			+ (ray.ro.z - obj.pos.z) * (ray.ro.z - obj.pos.z) - obj.r * obj.r;

	evo.det = evo.b * evo.b - 4 * evo.a * evo.c;
	if (evo.det > 0)
	{
		evo.ta = (-evo.b + sqrt(evo.det)) / (2 * evo.a);
		evo.tb = (-evo.b - sqrt(evo.det)) / (2 * evo.a);
		if (evo.ta > evo.tb && evo.ta < obj.r)
			return (evo.ta);
		return(evo.tb);
	}
	return (-1);
}
