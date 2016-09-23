/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:51:55 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/23 00:56:11 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void plan(register t_obj *obj, register t_ray ray)
{
    register double det;

    det = -((vector_scalar(obj->rotate, ray.a) -                               \
            vector_scalar(obj->rotate, obj->pos)) /                            \
            vector_scalar(obj->rotate, ray.b));
    if (det < 0)
    {
        obj->det = -1;
        return ;
    }
    obj->det = det;
}
