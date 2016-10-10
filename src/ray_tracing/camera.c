/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:06:30 by glodenos          #+#    #+#             */
/*   Updated: 2016/10/06 20:41:27 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_RT.h"

inline void camera(register t_cam cam, t_ray *ray, register size_t x,
        register size_t y)
{
    /* TODO refaire la camera   */

    ray->a.x = cam.pos.x;
    ray->a.y = cam.pos.y;
    ray->a.z = cam.pos.z;
    ray->b.x = (int)x - ((int)cam.w / 2) - cam.view.x;
    ray->b.y = (int)y - ((int)cam.h / 2) - cam.view.y;
    ray->b.z = cam.view.z;
    ray->b = vector_normalize(vector_sub(ray->b, ray->a));
}
