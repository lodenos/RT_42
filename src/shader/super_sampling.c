/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_sampling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 21:08:14 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/11 22:58:01 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    super_sampling(t_env *e, t_ray *ray, cl_float2 pos, size_t resolution)
{
    int     i;
    int     j;
    float   x;
    long double div;
    int     max;
    t_ray   tmp_ray[resolution * resolution];

    long double red = 0;
    long double green = 0;
    long double blue = 0;



    i = -1;
    x = pos.x;
    div = 1.0 / resolution;
    max = resolution * resolution;
    if (resolution == 0)
        ft_putstr_err("ERROR: supersampling -> resolution == 0", 1);
    while (++i < resolution)
    {
        j = -1;
        while (++j < resolution)
        {
            camera(e->scn.cam, &tmp_ray[(i * resolution) + j], pos.x, pos.y);
            run_raytracing(e, e->scn.obj, &tmp_ray[(i * resolution) + j]);
            pos.x += div;
        }
        pos.x = x;
        pos.y += div;
    }

    i = -1;

    while (++i < max)
    {
        red += tmp_ray[i].rgba.red;
        green += tmp_ray[i].rgba.green;
        blue += tmp_ray[i].rgba.blue;
    }
    ray->rgba.red = (unsigned char)((long double)red / (long double)max);
    ray->rgba.green = (unsigned char)((long double)green / (long double)max);
    ray->rgba.blue = (unsigned char)((long double)blue / (long double)max);
}
