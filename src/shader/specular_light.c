/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 05:01:11 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/04 22:36:28 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline double    power(register double x, register int y)
{
    register int    i;
    register float  val;

    i = 0;
    val = x;
    while (++i <= y)
        val *= x;
    return (val);
}

inline double           specular_light(register t_spt spt, register t_obj obj)
{
    register cl_float3  l;

    l = vector_normalize(vector_sub(spt.pos, obj.collision));
    return (power(vector_scalar(vector_reverse(l), vector_add(l,
    vector_mult_x(vector_mult_x(obj.normal, 2), vector_scalar(
    vector_reverse(obj.normal), l)))), 28) * spt.specular);
}
