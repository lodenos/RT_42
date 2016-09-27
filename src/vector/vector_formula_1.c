/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_formula_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 22:46:49 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/27 21:49:01 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline t_vec3   vector_add(register t_vec3 a, register t_vec3 b)
{
    register t_vec3 vect;

    vect.x = a.x + b.x;
    vect.y = a.y + b.y;
    vect.z = a.z + b.z;
    return (vect);
}

inline t_vec3   vector_normalize(register t_vec3 vect)
{
    register t_vec3 norm;
    register double value;

    value = 1 / sqrt(vector_scalar(vect, vect));
    norm.x = vect.x * value;
    norm.y = vect.y * value;
    norm.z = vect.z * value;
    return (norm);
}

inline t_vec3   vector_reverse(register t_vec3 vect)
{
    register t_vec3 rev;

    rev.x = -vect.x;
    rev.y = -vect.y;
    rev.z = -vect.z;
    return (rev);
}

inline double   vector_scalar(register t_vec3 a, register t_vec3 b)
{
    return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

inline t_vec3   vector_sub(register t_vec3 a, register t_vec3 b)
{
    register t_vec3 vector;

    vector.x = a.x - b.x;
    vector.y = a.y - b.y;
    vector.z = a.z - b.z;
    return (vector);
}
