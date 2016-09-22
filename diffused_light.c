/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffused_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 00:39:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 18:59:32 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double vec_scal(t_vec3d a, t_vec3d b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vec3d	vec_mult(t_vec3d v, double i)
{
	t_vec3d vec;

	vec.x = v.x * i;
	vec.y = v.y * i;
	vec.z = v.z * i;
	return (vec);
}

t_vec3d	get_vect(t_vec3d a, t_vec3d b)
{
		t_vec3d ab;

		ab.x = b.x - a.x;
		ab.y = b.y - a.y;
		ab.z = b.z - a.z;

		return (ab);
}

double	diffused_light(t_ray *ray, t_spt spt, t_obj obj)
{
	t_vec3d l;
	t_vec3d n;
	double z;
	(void)ray;

	l = get_vect(spt.pos, obj.norm);
	vecnorm(&l);
	n = get_vect(obj.pos, obj.norm);
	vecnorm(&n);
	/*r = vec_add(l, vec_mult(vec_mult(n, 2), vec_scal(reverse_vec(n), l)));*/
	/*z = power_nb(vec_scal(reverse_vec(l), r), 28);*/
	z = (vec_scal(l, n) * 0.9);
	/*
	if (z > 0)
	{
		ray->rgb.red = limit_rgb(ray->rgb.red + (spt.rgb.red * z));
		ray->rgb.green = limit_rgb(ray->rgb.green + (spt.rgb.green * z));
		ray->rgb.blue = limit_rgb(ray->rgb.blue + (spt.rgb.blue * z));
	}*/
	return (z);
}

/*
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
}*/
