/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_raytracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:22:41 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/28 22:32:17 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

void    run_raytracing(t_spt *spt, t_obj *obj, t_ray *ray)
{
    register size_t id;

    ray->rgba = (t_rgba){0, 0, 0, 255};
    id = check_object(obj, ray);
    if ((int)obj[id].det == -1)
        return ;
    ray->rgba = obj[id].rgba;
    obj[id].collision = coordinates_collision(ray->a, ray->b, obj[id].det);
    obj[id].normal = coordinates_collision(ray->a, ray->b, obj[id].det);
    light(spt, obj, id, ray);
}
