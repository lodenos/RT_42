/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 14:17:51 by anespoul          #+#    #+#             */
/*   Updated: 2016/09/21 12:05:56 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		vecnorm(t_vec3d *v)
{
	double id;

	id = 1 / sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	v->x *= id;
	v->y *= id;
	v->z *= id;
}

t_vec3d		vecadd(t_vec3d *v,  t_vec3d *u)
{
	t_vec3d vec;

	vec.x = v->x + u->x;
	vec.y = v->y + u->y;
	vec.z = v->z + u->z;
	return (vec);
}

t_vec3d		vecdot2(t_vec3d *v, double i)
{
	t_vec3d vec;

	vec.x = v->x * i;
	vec.y = v->y * i;
	vec.z = v->z * i;
	return (vec);
}

t_vec3d		veccopy(t_vec3d *v)
{
	t_vec3d copy;

	copy.x = v->x;
	copy.y = v->y;
	copy.z = v->z;
	return (copy);
}

t_vec3d		reverse_vec(t_vec3d v)
{
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	return (v);
}

double		power_nb(double x, int y)
{
	int i;
	double res;

	i = 1;
	res = x;
	while (i <= y)
	{
		res *= x;
		i++;
	}
	return (res);
}

t_vec3d		vecsub(t_vec3d *a, t_vec3d *b)
{
	t_vec3d vec;

	vec.x = a->x - b->x;
	vec.y = a->y - b->y;
	vec.z = a->z - b->z;
	return (vec);
}

double		vecdot(t_vec3d *a, t_vec3d *b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}
