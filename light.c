/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 00:49:37 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 14:57:16 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void            light(t_spt *spt, t_obj obj, t_ray *ray)
{
	int i;

	i = -1;
	while (spt[++i].end)
	{
		ray->rgb.blue = (ray->rgb.blue * spt[i].rgb.blue / 255) *
			((0.2 + diffused_light(obj, *ray, *spt)) / 2);
		ray->rgb.green = (ray->rgb.green * spt[i].rgb.green / 255) *
			((0.2 + diffused_light(obj, *ray, *spt)) / 2);
		ray->rgb.red = (ray->rgb.red * spt[i].rgb.red / 255) *
			((0.2 + diffused_light(obj, *ray, *spt)) / 2);
		spec_light(ray, spt[i], obj);
	}
}
