/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:22:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/28 01:55:05 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

/* TODO Algo MASTER DU RT FAITE PAS CHIER CODEZ PROPRE !!!   */
void    run_raytracing(t_spt *spt, t_obj *obj, t_ray *ray)
{
    register int    i;
    register int    index;
    register double tmin;

    i = -1;
    tmin = 20000;
    index = 0;
    ray->rgba = (t_rgba){0, 0, 0, 255};
    while (obj[++i].end)
    {
        obj[i].ft(&obj[i], *ray);
        if (0 <= obj[i].det && obj[i].det <= tmin)
        {
            tmin = obj[i].det;
            index = i;
        }
    }
    if ((int)obj[index].det == -1)
        return ;
    ray->rgba = obj[index].rgba;
    obj[index].collision = coordinates_collision(ray->a, ray->b, obj[index].det);
    obj[index].normal = coordinates_collision(ray->a, ray->b, obj[index].det);
    light(spt, obj[index], ray);
}
