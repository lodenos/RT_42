/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 22:36:44 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/06 16:23:45 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline t_ray    vector_rotate_ray(register t_ray ray, register cl_float3 pos,
        register cl_float3 rotate)
{
    ray.a = vector_sub(ray.a, pos);
    ray.b = vector_sub(ray.b, pos);
    ray.a = matrix_rotate(ray.a, rotate);
    ray.b = matrix_rotate(ray.b, rotate);
    ray.b = vector_normalize(vector_sub(ray.b, ray.a));
    return (ray);
}
