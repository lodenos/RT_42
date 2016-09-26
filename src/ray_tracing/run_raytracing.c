/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:22:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/26 17:22:16 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    run_raytracing(t_spt *spt, t_obj *obj, t_ray *ray)
{                
    /* TODO Algo MASTER DU RT FAITE PAS CHIER CODEZ PROPRE !!!   */
    register int    i;
    register int    index;
    register double tmin;


    ray->rgba = (t_rgba){0, 0, 0, 255};
    (void)spt;
    i = 0;
    tmin = 20000;
    index = 0;
    while (obj[i].end)
    {
        obj[i].ft(&obj[i], *ray);
        if (0 <= obj[i].det && obj[i].det <= tmin)
        {
            tmin = obj[i].det;
            index = i;
        }
        ++i;
    }
    if ((int)obj[index].det == -1)
        return ;
    ray->rgba = obj[index].rgba;
    light(spt, obj[index], ray);
}
