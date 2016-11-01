/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:26 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/06 17:22:45 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline float    cone(register t_obj obj, register t_ray ray)
{
    register float  a;
    register float  b;
    register float  c;
    register float  ta;
    register float  tb;
    register float  det;

    a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z - ray.dir.y * ray.dir.y *
            obj.angle;
    b = 2.0f * ((ray.pos.x - obj.pos.x) * ray.dir.x +
            (ray.pos.z - obj.pos.z) * ray.dir.z -
            (ray.pos.y - obj.pos.y) * ray.dir.y * obj.angle);
    c = ((ray.pos.x - obj.pos.x) * (ray.pos.x - obj.pos.x)) +
            ((ray.pos.z - obj.pos.z) * (ray.pos.z - obj.pos.z)) -
            ((ray.pos.y - obj.pos.y) * (ray.pos.y - obj.pos.y)) * obj.angle  -
            obj.radius * obj.radius;
    det = b * b - 4.0f * a * c;
    if (det > 0.0f)
    {
        ta = (-b + sqrtf(det)) / (2.0f * a);
        tb = (-b - sqrtf(det)) / (2.0f * a);
        return (ta > tb) ? tb : ta;
    }
    return (-1.0f);
}
