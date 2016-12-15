/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_collision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 03:56:23 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:34:59 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

inline cl_float3	coordinates_collision(register cl_float3 a,
		register cl_float3 b, register float det)
{
	register cl_float3	vect;

	vect.x = a.x + b.x * det;
	vect.y = a.y + b.y * det;
	vect.z = a.z + b.z * det;
	return (vect);
}
