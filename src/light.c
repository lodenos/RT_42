/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 00:49:37 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 01:26:09 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    light(t_spt *spt, t_obj obj, t_ray *ray)
{
    ray->rgb.blue = (ray->rgb.blue * spt[0].rgb.blue / 255) *
        ((0.4 + diffused_light(obj, *ray)) / 2);
    ray->rgb.green = (ray->rgb.green * spt[0].rgb.green / 255) *
        ((0.4 + diffused_light(obj, *ray)) / 2);
    ray->rgb.red = (ray->rgb.red * spt[0].rgb.red / 255) *
        ((0.4 + diffused_light(obj, *ray)) / 2);
    specular_light(ray, spt[0], obj);
}
