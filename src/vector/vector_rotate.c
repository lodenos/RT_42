/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 22:36:44 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/02 02:43:58 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline t_vec3   vector_rotate(t_vec3 vec, double angle)
{
    double  v_cos;  // cos angle
    double  i_cos;  // 1 / cos angle
    double  v_sin;  // sin angle

    v_cos = cos(angle);
    i_cos = 1 / v_cos;
    v_sin = sin(angle);

    vec.x = vec.x * vec.x * i_cos + v_cos +
            vec.x * vec.y * i_cos - vec.z * v_sin +
            vec.x * vec.z * i_cos + vec.y * v_sin;

    vec.y = vec.x * vec.y * i_cos + vec.z * v_sin +
            vec.y * vec.y * i_cos + v_cos +
            vec.y * vec.z * i_cos - vec.x * v_sin;

    vec.z = vec.x * vec.z * i_cos - vec.y * v_sin +
            vec.y * vec.z * i_cos + vec.x * v_sin +
            vec.z * vec.z * i_cos + v_cos;

    return (vec);
}