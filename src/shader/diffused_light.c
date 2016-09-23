/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffused_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 04:50:32 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/23 05:42:29 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline double   diffused_light(register t_obj obj, register t_ray ray)
{
    register double a;
    register double b;
    register double c;

    a = sqrt(((ray.a.x - obj.pos.x) * (ray.a.x - obj.pos.x)) +    \
            ((ray.a.y - obj.pos.y) * (ray.a.y - obj.pos.y)) +     \
            ((ray.a.z - obj.pos.z) * (ray.a.z - obj.pos.z)));
    b = sqrt(((obj.normal.x - obj.pos.x) * (obj.normal.x - obj.pos.x)) +    \
            ((obj.normal.y - obj.pos.y) * (obj.normal.y - obj.pos.y)) +     \
            ((obj.normal.z - obj.pos.z) * (obj.normal.z - obj.pos.z)));
    c = sqrt(((ray.a.x - obj.normal.x) * (ray.a.x - obj.normal.x)) +  \
            ((ray.a.y - obj.normal.y) * (ray.a.y - obj.normal.y)) +   \
            ((ray.a.z - obj.normal.z) * (ray.a.z - obj.normal.z)));
    return (1 - cos(asin(((a * a) + (b * b) - (c * c)) / (2 * a * b))));
}
