/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_collision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:56:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/23 07:13:57 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline t_vec3   coordinates_collision(register t_vec3 a, register t_vec3 b,
        register double det)
{
    t_vec3  vect;

    vect.x = a.x + b.x * det;
    vect.y = a.y + b.y * det;
    vect.z = a.z + b.z * det;


    return (vect);
}
