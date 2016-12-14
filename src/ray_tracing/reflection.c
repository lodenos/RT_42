/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:47:39 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/01 13:20:57 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"


while (i < 20)
{
    ray->pos = obj_tmp.collision;
    ray->dir = sub(ray->dir, vector_mult_x(vector_mult_x(obj_tmp.normal,
            dot(obj_tmp.normal, ray->dir)), 2));
    det = check_object(obj, *ray, &id, id);
    if (det == -1)
        return ;

    det += 0.01;

    color = ray->color;
    obj_tmp = obj[id];
    obj_tmp.collision = coordinates_collision(ray->pos, ray->dir, det);
    get_normal_object(&obj_tmp, *ray, det);
    bump_mapping(&obj_tmp);
    light(e, id, obj_tmp, ray);
    if (obj_tmp.reflexion == 0)
        return ;
    ++i;
}

if (obj_tmp.reflexion > 0)
    ray->color = 0x0;
