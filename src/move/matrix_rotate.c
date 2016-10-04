/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:24:21 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/04 23:19:35 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline cl_float3    matrix_rotate(register cl_float3 point,
        register cl_float3 rot)
{
    /* Rotate Axe x */
    point.y = point.y * cos(rot.x) - point.z * sin(rot.x);
    point.z = point.y * sin(rot.x) + point.z * cos(rot.x);
    /* Rotate Axe y */
    point.x = point.x * cos(rot.y) + point.z * sin(rot.y);
    point.z = point.x * -sin(rot.y) + point.z * cos(rot.y);
    /* Rotate Axe z */
    point.x = point.x * cos(rot.z) - point.y * sin(rot.z);
    point.y = point.x * sin(rot.z) + point.y * cos(rot.z);
    return (point);
}
