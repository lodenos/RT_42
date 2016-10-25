/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:11 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/06 17:10:48 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline float    sphere(register t_obj obj, register t_ray ray)
{
    register float  b;
    register float  c;

    ray.pos = sub(ray.pos, obj.pos);
    b = dot(ray.pos, ray.dir);
    c = b * b - (dot(ray.pos, ray.pos) - obj.radius * obj.radius);
    if (c < 0.0f)
       return (-1);
    c = sqrtf(c);
    return (-b - c > 0) ? -b - c : -b + c;
}
