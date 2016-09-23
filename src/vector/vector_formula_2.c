/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_formula_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 22:46:55 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/22 23:22:26 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline t_vec3   vector_mult_x(register t_vec3 vect, register double x)
{
    register t_vec3 v;

    v.x = vect.x * x;
    v.y = vect.y * x;
    v.z = vect.z * x;
    return (v);
}
