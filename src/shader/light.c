/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:50:04 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/23 06:37:30 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    light(t_spt *spt, t_obj obj, t_ray *ray)
{
    /* TODO Experimantal */
/*    ray->rgba.blue = (ray->rgba.blue * spt[0].rgba.blue / 255) *
            ((0.0 + diffused_light(obj, *ray)) / 2);
    ray->rgba.green = (ray->rgba.green * spt[0].rgba.green / 255) *
            ((0.0 + diffused_light(obj, *ray)) / 2);
    ray->rgba.red = (ray->rgba.red * spt[0].rgba.red / 255) *
            ((0.0 + diffused_light(obj, *ray)) / 2);*/
    specular_light(ray, spt[0], obj);
}
