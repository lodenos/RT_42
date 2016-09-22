/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 21:53:16 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 17:30:03 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void fill_color(t_ray *ray, t_obj *obj)
{
    ray->rgb.blue = obj->rgb.blue;
    ray->rgb.green = obj->rgb.green;
    ray->rgb.red = obj->rgb.red;
}

void        run_raytracing(t_spt *spt, t_obj *obj, t_ray *ray)
{
	int     i;

	i = -1;
	ray->tmin = 20000;
	while (obj[++i].end)
	{
		obj[i].det = obj[i].ft(obj[i], *ray); /* calcul ray = obj-cam */
		if (0 <= obj[i].det && obj[i].det <= ray->tmin)
		{
			ray->tmin = obj[i].det;
			ray->index = i;
		}
	}
	if (obj[ray->index].det == -1)
		return ;
	coordinates_collision(&obj[ray->index], *ray); /*coord point inter */
	fill_color(ray, &obj[ray->index]);
	light(spt, obj[ray->index], ray);
}
/*
void        run_raytracing(t_spt *spt, t_obj *obj, t_ray *ray)
{
	int     i;

	(void)spt;
	i = -1;
	ray->tmin = 20000;
	while (obj[++i].end)
	{
		obj[i].det = obj[i].ft(obj[i], *ray);  calcul ray = obj-cam 
		if (0 <= obj[i].det && obj[i].det <= ray->tmin)
		{
			ray->tmin = obj[i].det;
			ray->index = i;
		}
	}
	if (obj[ray->index].det == -1)
		return ;
	coordinates_collision(&obj[ray->index], *ray); coord point inter

	fill_color(ray, &obj[ray->index]);
	light(spt, obj[ray->index], ray);
}*/
