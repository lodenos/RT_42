/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 05:01:11 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/28 01:48:24 by glodenos         ###   ########.fr       */
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

void                    specular_light(t_ray *ray, register t_spt spt,
        register t_obj obj)
{
    register t_vec3 l;
    register t_vec3 n;
    register double z;

    l = vector_normalize(vector_sub(spt.pos, obj.normal));
    n = vector_normalize(vector_sub(obj.pos, obj.normal));
    z = power(vector_scalar(vector_reverse(l), vector_add(l,
            vector_mult_x(vector_mult_x(n, 2), vector_scalar(
            vector_reverse(n), l)))), 20);
    z = z * 0.1; /*coef speculaire*/
    if (z > 0)
    {
        ray->rgba.red = limit_rgba(ray->rgba.red + spt.rgba.red * z);
        ray->rgba.green = limit_rgba(ray->rgba.green + spt.rgba.green * z);
        ray->rgba.blue = limit_rgba(ray->rgba.blue + spt.rgba.blue * z);
    }
}
