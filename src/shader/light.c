/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:50:04 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 17:32:41 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    light(t_spt *spt, t_obj obj, t_ray *ray)
{
    /* TODO Experimantal */

    ray->rgba.red = (unsigned char)(diffused_light(obj, *ray) * 255);
    ray->rgba.green = (unsigned char)(diffused_light(obj, *ray) * 255);
    ray->rgba.blue = (unsigned char)(diffused_light(obj, *ray) * 255);
    specular_light(ray, spt[0], obj);
}
