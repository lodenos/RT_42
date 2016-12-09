/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:24:21 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/09 13:12:28 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline cl_float3	rotate_x(register cl_float3 point,
		register float angle)
{
	point.y = point.y * cosf(angle) - point.z * sinf(angle);
	point.z = point.y * sinf(angle) + point.z * cosf(angle);
	return (point);
}

inline cl_float3	rotate_y(register cl_float3 point,
		register float angle)
{
	point.x = point.x * cosf(angle) + point.z * sinf(angle);
	point.z = point.x * -sinf(angle) + point.z * cosf(angle);
	return (point);
}

inline cl_float3	rotate_z(register cl_float3 point,
		register float angle)
{
	point.x = point.x * cosf(angle) - point.y * sinf(angle);
	point.y = point.x * sinf(angle) + point.y * cosf(angle);
	return (point);
}
