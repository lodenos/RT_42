/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 04:15:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/28 04:30:36 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void bump_mapping(t_obj *obj)
{
    cl_float3   tmp;
    int           x;
    int           y;
    int           z;

    if (obj->type_bump == 0)
        return ;
    else if (obj->type_bump == 1)
    {
        tmp = sub(obj->collision, obj->pos);
        obj->normal.x -= sinf(tmp.x) * 0.01f;
        obj->normal.y -= sinf(tmp.y) * 0.01f;
        obj->normal.z -= sinf(tmp.z) * 0.01f;
    }
    else if (obj->type_bump == 2)
    {
        tmp = sub(obj->collision, obj->pos);
        x = (abs((int)tmp.x / 5)) % 2;
        y = (abs((int)tmp.y / 5)) % 2;
        z = (abs((int)tmp.z / 5)) % 2;
        if (z)
            obj->color = ((x && y) || (!x && !y)) ? 0xFFFFFFFF : 0xFF;
            
        else 
           obj->color = ((x && y) || (!x && !y)) ? 0xFF : 0xFFFFFFFF;
    }
    //else if (obj->type_bump == 3)
     //   perlin_noise();
}