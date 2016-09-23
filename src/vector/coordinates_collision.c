/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_collision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:56:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/09/23 04:45:44 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline t_vec3   coordinates_collision(register t_vec3 a, register t_vec3 b,
        register double det)
{
    return (vector_mult_x(vector_add(a, b), det));
}
