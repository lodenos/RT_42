/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:46 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/11 15:08:22 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline float    cylinder(register t_obj obj, register t_ray ray)
{
    register float  a;
    register float  b;
    register float  c;
    register float  x;
    register float  y;

    ray.pos = sub(ray.pos, obj.pos);
    x = dot(ray.dir, obj.rotate);
    y = dot(ray.pos, obj.rotate);
    a = dot(ray.dir, ray.dir) - x * x;
    b = dot(ray.pos, ray.dir) - x * y;
    c = b * b - a * (dot(ray.pos, ray.pos) - obj.radius * obj.radius - y * y);
    if (c < 0.0f)
        return (-1);
    c = sqrt(c);
    return ((-b - c > 0) ? -b - c : -b + c);
}
