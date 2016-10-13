/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_formula_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 22:46:49 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/06 20:41:53 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline cl_float3    vector_add(register cl_float3 a, register cl_float3 b)
{
    register cl_float3  vect;

    vect.x = a.x + b.x;
    vect.y = a.y + b.y;
    vect.z = a.z + b.z;
    return (vect);
}

inline cl_float3    vector_normalize(register cl_float3 vect)
{
    register cl_float3  norm;
    register double     value;

    value = 1 / sqrt(vector_scalar(vect, vect));
    norm.x = vect.x * value;
    norm.y = vect.y * value;
    norm.z = vect.z * value;
    return (norm);
}

inline cl_float3    vector_reverse(register cl_float3 vect)
{
    register cl_float3  rev;

    rev.x = -vect.x;
    rev.y = -vect.y;
    rev.z = -vect.z;
    return (rev);
}

inline float        vector_scalar(register cl_float3 a, register cl_float3 b)
{
    return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

inline cl_float3    vector_sub(register cl_float3 a, register cl_float3 b)
{
    register cl_float3  vector;

    vector.x = a.x - b.x;
    vector.y = a.y - b.y;
    vector.z = a.z - b.z;
    return (vector);
}
