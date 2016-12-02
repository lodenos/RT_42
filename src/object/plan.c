/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:55 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/03 14:59:14 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline float    plan(register t_obj obj, register t_ray ray)
{
    register float  a;
    register float  b;

    if ((a = dot(ray.dir, obj.rotate)) < 0.0f)
    {
        if ((a = dot(ray.dir, reverse(obj.rotate))) < 0.0f)
            return (-1);
        if ((b = -(dot(reverse(obj.rotate), sub(ray.pos, obj.pos_a)) / a)) < 0.0f)
            return (-1);
        return (b);
    }
    if ((b = -(dot(obj.rotate, sub(ray.pos, obj.pos_a)) / a)) < 0.0f)
        return (-1);
    return (b);
}
