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

    if (obj->type_bump == 0)
        return ;
    else if (obj->type_bump == 1)
    {
        tmp = sub(obj->collision, obj->pos);
        obj->normal.x -= sinf(tmp.x) * 0.1f;
        obj->normal.y -= sinf(tmp.y) * 0.1f;
        obj->normal.z -= sinf(tmp.z) * 0.1f;
    }
    else if (obj->type_bump == 2)
    {
        if ((int)(obj->collision.x + obj->collision.y + obj->collision.z -
                obj->pos.x + obj->pos.y + obj->pos.z) % 2)
            obj->color /= 2;
    }
}
