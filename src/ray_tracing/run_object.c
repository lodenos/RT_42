/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:43:14 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/15 13:31:22 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_rt.h"

inline float	run_object(register t_obj obj, register t_ray ray)
{
	if (obj.type == CONE)
		return (cone(obj, ray));
	else if (obj.type == CYLINDER)
		return (cylinder(obj, ray));
	else if (obj.type == PLAN)
		return (plan(obj, ray));
	else if (obj.type == SPHERE)
		return (sphere(obj, ray));
	else if (obj.type == TORUS)
		return (torus(obj, ray));
	else if (obj.type == TRIANGLE)
		return (triangle(obj, ray));
	else if (obj.type == ELLIPSOID)
		return (ellipsoid(obj, ray));
	return (-1);
}
