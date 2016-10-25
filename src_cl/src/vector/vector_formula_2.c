/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_formula_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 22:46:55 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/06 20:42:12 by glodenos         ###   ########.fr       */
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
