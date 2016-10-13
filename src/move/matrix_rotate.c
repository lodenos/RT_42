/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:24:21 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/05 15:21:40 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline cl_float3    matrix_rotate(register cl_float3 point,
        register cl_float3 rot)
{
    /* Rotate Axe x */
    point.y = point.y * cosf(rot.x) - point.z * sinf(rot.x);
    point.z = point.y * sinf(rot.x) + point.z * cosf(rot.x);
    /* Rotate Axe y */
    point.x = point.x * cosf(rot.y) + point.z * sinf(rot.y);
    point.z = point.x * -sinf(rot.y) + point.z * cosf(rot.y);
    /* Rotate Axe z */
    point.x = point.x * cosf(rot.z) - point.y * sinf(rot.z);
    point.y = point.x * sinf(rot.z) + point.y * cosf(rot.z);
    return (point);
}
