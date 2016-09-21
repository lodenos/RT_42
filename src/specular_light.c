/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 22:02:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 01:24:24 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static unsigned char    limit_rgb(int x)
{
    if (x > 255)
        return (0xFF);
    else if (x < 0)
        return (0x00);
    else
        return ((unsigned char)x);
}

void	                specular_light(t_ray *ray, t_spt spt, t_obj obj)
{
    t_vec3  l;
    t_vec3  n;
    t_vec3  r;
    double	z;

    l = vector_normalize(vector_sub(obj.norm, spt.pos));
    n = vector_normalize(vector_sub(obj.norm, obj.pos));
    r = vector_add(l, vector_mult_x(vector_mult_x(n, 2),
                vector_scalar(vector_reverse(n), l)));
    z = pow(vector_scalar(vector_reverse(l), r), 25);
    ray->rgb.red   = limit_rgb((int)(ray->rgb.red   + (spt.rgb.red   * z)));  
    ray->rgb.green = limit_rgb((int)(ray->rgb.green + (spt.rgb.green * z)));
    ray->rgb.blue  = limit_rgb((int)(ray->rgb.blue  + (spt.rgb.blue  * z)));
}
