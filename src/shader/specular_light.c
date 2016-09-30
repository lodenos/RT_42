/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 05:01:11 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/30 03:44:05 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static inline double    power(register double x, register int y)
{
	register int    i;
	register double val;

	i = 0;
	val = x;
	while (++i <= y)
		val *= x;
	return (val);
}

double                  specular_light(register t_spt spt, register t_obj obj)
{
    register t_vec3 l;
    register t_vec3 n;

    l = vector_normalize(vector_sub(spt.pos, obj.normal));
    n = vector_normalize(vector_sub(obj.pos, obj.normal));
    return (power(vector_scalar(vector_reverse(l), vector_add(l,
            vector_mult_x(vector_mult_x(n, 2), vector_scalar(
            vector_reverse(n), l)))), 28));
}
