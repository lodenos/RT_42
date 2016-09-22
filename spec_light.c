/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:26:00 by anespoul          #+#    #+#             */
/*   Updated: 2016/09/22 18:02:53 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		limit_rgb(int x)
{
	if (x > 255)
		return (255);
	else if (x < 0)
		return (0);
	else
		return (x);
}

void	spec_light(t_ray *ray, t_spt spt, t_obj obj)
{
	t_vec3d l;
	t_vec3d n;
	t_vec3d r;
	t_vec3d tmp;
	double	z;

	l = vecsub(&obj.norm, &spt.pos);
	vecnorm(&l);
	n = vecsub(&obj.norm, &obj.pos);
	vecnorm(&n);

	r = reverse_vec(n);
	z = vecdot(&r, &l);
	r = vecdot2(&n, 2);
	r = vecdot2(&r, z);
	r = vecadd(&l, &r);
	tmp = reverse_vec(l);
	z = vecdot(&tmp, &r);
	z = power_nb(z, 28);
	if (z > 0)
	{
		ray->rgb.red = limit_rgb(ray->rgb.red + (spt.rgb.red * z));
		ray->rgb.green = limit_rgb(ray->rgb.green + (spt.rgb.green * z));
		ray->rgb.blue = limit_rgb(ray->rgb.blue + (spt.rgb.blue * z));
	}
}
