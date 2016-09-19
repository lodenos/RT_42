/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 21:53:16 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/19 03:52:47 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

static int  first_object(t_obj *obj, int i, int j)
{
    if (obj[j].end == 0)
        return (i);
    if (obj[i].det > obj[j].det)
        return (first_object(obj, i, j + 1));
    else
        return (first_object(obj, j, i + 1));
}

void        run_raytracing(t_spt *spt, t_obj *obj, t_ray *ray)
{
    int     i;

    (void)spt;
    i = -1;
    ray->rgb = 0;
    while (obj[++i].end)
    {
        obj[i].det = obj[i].ft(obj[i], *ray);
        coordinates_collision(&obj[i], *ray);
    }
    i = first_object(obj, 0, 1);
    if (obj[i].det == -1.0)
        return ;
    ray->rgb = obj[i].rgb;
    light(spt, obj[i], ray);
}
