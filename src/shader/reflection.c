/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:25:17 by nrandria          #+#    #+#             */
/*   Updated: 2016/10/26 15:25:22 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lib_RT.h"

inline cl_float3 reflection(t_obj *obj, t_ray *ray)
{
    register cl_float3 reflct;

    reflct = sub(ray->dir, vector_mult_x(obj->normal, (2 * dot(ray->dir, obj->normal))));

    return (reflct);
}
