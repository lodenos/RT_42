/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:43:14 by glodenos          #+#    #+#             */
/*   Updated: 2016/12/09 14:07:27 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

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
		return (sphere(obj, ray));
	else if (obj.type == TRIANGLE)
		return (sphere(obj, ray));
	return (-1);
}
