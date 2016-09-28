/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffused_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 04:50:32 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/28 01:45:47 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"
#include <stdio.h>

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

void   diffused_light(t_ray *ray, register t_spt spt, register t_obj obj)
{
    register t_vec3 l;
    register t_vec3 n;
    register double z;
    register double sommel;
    register double sommen;

    l = vector_normalize(vector_sub(obj.collision, spt.pos));
    n = vector_normalize(vector_sub(obj.collision, obj.pos));
    z = vector_scalar(l,n);
    z = z * -1;

/*    if (obj.collision.y > 180)
    {
    	printf("obj.collision = (%lf, %lf, %lf), spt.pos = (%lf, %lf, %lf), obj.pos = (%lf, %lf, %lf)\n", 
    		obj.collision.x, obj.collision.y, obj.collision.z, spt.pos.x, spt.pos.y, spt.pos.z, obj.pos.x, obj.pos.y, obj.pos.z);
    }
    sommel = sqrt(l.x * l.x + l.y * l.y + l.z * l.z);
    sommen = sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
    printf("z = %lf, l = (%lf, %lf, %lf) somme = %lf, n = (%lf, %lf, %lf) somme = %lf\n", z, l.x, l.y, l.z, sommel, n.x, n.y, n.z, sommen);*/

       ray->rgba.red = limit_rgba(((ray->rgba.red + spt.rgba.red) / 2) * z);
       ray->rgba.green = limit_rgba(((ray->rgba.green + spt.rgba.green) / 2) * z);
       ray->rgba.blue = limit_rgba(((ray->rgba.blue + spt.rgba.blue) / 2) * z);
    
}
