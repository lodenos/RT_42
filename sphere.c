/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 22:10:12 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 16:59:21 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		sphere(t_obj obj, t_ray ray)
{
	t_evo	evo;
	t_vec3d	d;

	evo.a = vecdot(&ray.rd, &ray.rd);
	d = vecsub(&ray.ro, &obj.pos);
	evo.b = 2 * (vecdot(&ray.rd, &d));
	evo.c = vecdot(&d, &d) - obj.r * obj.r;
	evo.det = evo.b * evo.b - 4 * evo.a * evo.c;
	if (evo.det >= 0)
	{
		evo.ta = (-evo.b + sqrt(evo.det)) / (2 * evo.a);
		evo.tb = (-evo.b - sqrt(evo.det)) / (2 * evo.a);
		if (evo.ta > evo.tb)
			return (evo.tb);
		return (evo.ta);
	}
	return (-1);
}
