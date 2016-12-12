/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_formula_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 22:46:55 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/05 13:22:57 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline cl_float3    vector_mult_x(register cl_float3 vect, register float x)
{
    register cl_float3  v;

    v.x = vect.x * x;
    v.y = vect.y * x;
    v.z = vect.z * x;
    return (v);
}

inline cl_float3    vector_mult(register cl_float3 a, register cl_float3 b)
{
    register cl_float3  tmp;

    tmp.x = a.x * b.x;
    tmp.y = a.y * b.y;
    tmp.z = a.z * b.z;
    return (tmp);
}

inline cl_float3	cross(register cl_float3 a, register cl_float3 b)
{
	register cl_float3 vec;

	vec.x = a.y * b.z - a.z * b.y;
	vec.y = a.z * b.x - a.x * b.z;
	vec.z = a.x * b.y - a.y * b.x;
	return (vec);
}

inline cl_float3	vector_div(register cl_float3 a, register float x)
{
	register cl_float3 vec;

	vec.x = a.x / x;
	vec.y = a.y / x;
	vec.z = a.z / x;
	return (vec);
}

inline float	vector_len(register cl_float3 a)
{
	register float len;

	len = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return (len);
}
