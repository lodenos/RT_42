/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffused_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 04:50:32 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/08 02:07:43 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

/* TODO   Corrige Ambient                           */
/* TODO   Erreur de fusion de la lumiere et objet   */

inline void diffused_light(t_ray *ray, register t_spt spt, register t_obj obj)
{
    register float  z;

    z = -(dot(normalize(sub(obj.collision, spt.pos)), obj.normal) * spt.diffuse);
    ray->color = (unsigned int)limit_rgba((((unsigned char)(ray->color >> 24) +
            (unsigned char)(spt.color >> 24)) / 2) * z) << 24 |
            (unsigned int)limit_rgba((((unsigned char)(ray->color >> 16) +
            (unsigned char)(spt.color >> 16)) / 2) * z) << 16 |
            (unsigned int)limit_rgba((((unsigned char)(ray->color >> 8) +
            (unsigned char)(spt.color >> 8)) / 2) * z) << 8 |
            (unsigned int)limit_rgba((((unsigned char)ray->color +
            (unsigned char)spt.color) / 2) * z);
}
