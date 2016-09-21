/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_formula_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:36:17 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/21 17:10:04 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

t_vec3  vector_add(t_vec3 a, t_vec3 b)
{
    t_vec3  vect;
    
    vect.x = a.x + b.x;
    vect.y = a.y + b.y;
    vect.z = a.z + b.z;
    return (vect);
}

t_vec3  vector_normalize(t_vec3 vect)
{
    t_vec3  norm;
    double  value;

    value = 1 / sqrt((vect.x * vect.x) + (vect.y * vect.y) +
            (vect.z * vect.z));
    norm.x = vect.x * value;
    norm.y = vect.y * value;
    norm.z = vect.z * value;
    return (norm);
}

t_vec3  vector_reverse(t_vec3 vect)
{
    t_vec3  rev;

    rev.x = -vect.x;
    rev.y = -vect.y;
    rev.z = -vect.z;
    return (rev);
}

double  vector_scalar(t_vec3 a, t_vec3 b)
{
    return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vec3  vector_sub(t_vec3 a, t_vec3 b)
{
    t_vec3  vector;

    vector.x = a.x - b.x;
    vector.y = a.y - b.y;
    vector.z = a.z - b.z;
    return (vector);
}
