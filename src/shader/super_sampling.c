/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_sampling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 21:08:14 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/12 13:46:06 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    super_sampling(t_env *e, t_ray *ray, cl_float2 pos, size_t resolution)
{
    int     i;
    int     j;
    float   x;
    double  div;
    int     max;

    i = -1;
    x = pos.x;
    div = 1.0 / resolution;
    max = resolution * resolution;
    ray->red = 0;
    ray->green = 0;
    ray->blue = 0;
    if (resolution == 0)
        ft_putstr_err("ERROR: supersampling -> resolution == 0", 1);
    while (++i < resolution)
    {
        j = -1;
        while (++j < resolution)
        {
            camera(e->scn.cam, ray, pos.x, pos.y);
            run_raytracing(e, e->scn.obj, ray);
            pos.x += div;
            ray->red += ray->rgba.red;
            ray->green += ray->rgba.green;
            ray->blue += ray->rgba.blue;
        }
        pos.x = x;
        pos.y += div;
    }
    ray->rgba.red   = (unsigned char)((ray->red / (double)max));
    ray->rgba.green = (unsigned char)((ray->green / (double)max));
    ray->rgba.blue  = (unsigned char)((ray->blue / (double)max));
}
