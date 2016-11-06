/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 05:01:11 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/01 00:16:08 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline float power(register float x, register int y)
{
    register int    i;
    register float  val;

    i = 0;
    val = x;
    while (++i <= y)
        val *= x;
    return (val);
}

float               specular_light(register t_spt spt, register t_obj obj)
{
    register cl_float3  l;

    l = normalize(sub(spt.pos, obj.collision));
    return (power(dot(reverse(l), add(l, vector_mult_x(
            vector_mult_x(obj.normal, 2), dot(reverse(obj.normal), l)))), 80));
}
